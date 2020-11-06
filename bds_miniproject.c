#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
//stck for each movie char
char stck_f_name_avenger[16][100];char stck_l_name_avenger[16][100];
char stck_l_name_spiderman[16][100];char stck_f_name_spiderman[16][100];
char stck_l_name_sadak2[16][100];char stck_f_name_sadak2[16][100];
char stck_l_name_singham[16][100];char stck_f_name_singham[16][100];
int top_f_name_avenger=-1;int top_l_name_avenger=-1;
int top_f_name_spiderman=-1;int top_l_name_spiderman=-1;
int top_f_name_sadak2=-1;int top_l_name_sadak2=-1;
int top_f_name_singham=-1;int top_l_name_singham=-1;
int bookingid_avenger[16];int top_bookingid_avenger=-1;
int bookingid_spiderman[16];int top_bookingid_spiderman=-1;
int bookingid_sadak2[16];int top_bookingid_sadak2=-1;
int bookingid_singham[16];int top_bookingid_singham=-1;
int max_avenger=15;
int max_spiderman=15;
int max_sadak2=15;
int max_singham=15;
int avenger_stck[16];
int spiderman_stck[16];
int sadak2_stck[16];
int singham_stck[16];
int top_avenger=-1;
int selection_seat2;
int top_spiderman=-1;
int top_sadak2=-1;
int top_singham=-1;
//stck for movie seats
int max_avengerplt_seat=2;
int max_spidermanplt_seat=2;
int max_sadak2plt_seat=5;
int max_singhamplt_seat=5;
int max_avengergold_seat=5;
int max_spidermangold_seat=5;
int max_sadak2gold_seat=5;
int max_singhamgold_seat=5;
int max_avengersil_seat=5;
int max_spidermansil_seat=5;
int max_sadak2sil_seat=5;
int max_singhamsil_seat=5;
int avenger_stck_pt[6];
int spiderman_stck_pt[6];
int sadak2_stck_pt[6];
int singham_stck_pt[6];
int avenger_stck_gold[6];
int spiderman_stck_gold[6];
int sadak2_stck_gold[6];
int singham_stck_gold[6];
int avenger_stck_sil[6];
int spiderman_stck_sil[6];
int sadak2_stck_sil[6];
int singham_stck_sil[6];
int top_avenger_pt=-1;
int top_spiderman_pt=-1;
int top_sadak2_pt=-1;
int top_singham_pt=-1;
int top_avenger_gold=-1;
int top_spiderman_gold=-1;
int top_sadak2_gold=-1;
int top_singham_gold=-1;
int top_avenger_sil=-1;
int top_spiderman_sil=-1;
int top_sadak2_sil=-1;
int top_singham_sil=-1;
//functions
struct theatre(th);
struct theatre(th1);
//int food_wish();
int selection_seat_fn(int x); //FUNCTION TO SELECT SEAT
int editing_admin(temp);
int purchasing(th);// function for purchasing the ticket
int cancel(th); // function to cancel the ticket
void details();  //function for the bill
void ticket_avenger(th); //for displaying the bill of avenger
void ticket_spiderman(); //for displaying the bill of spiderman
void ticket_sadak2(); //for displaying the bill of sadak2
void ticket_singham(); //for displaying the bill of singham
char pre_pass[100]="miniproject"; //predefined password for both admin & customer
int bookingid_final;//booking id to be stored after ticket bought for camparing
void avenger_plt_seat();
void avenger_gold_seat();
void avenger_sil_seat();
void spiderman_plt_seat();
void spiderman_gold_seat();
void spiderman_sil_seat();
void singham_plt_seat();
void singham_gold_seat();
void singham_sil_seat();
void sadak2_plt_seat();
void sadak2_gold_seat();
void sadak2_sil_seat();
char f_name[100];
char l_name[100];
void SetColor(int ForgC);
int platinum_price =500;
int gold_price=400;
int silver_price=300;

struct theatre
{

   int id_avenger_pt; //booking id of the customer FOR AVENGER MOVIE
   int id_avenger_gold;
   int id_avenger_sil;
   int id_spiderman_pt; //booking id of the customer FOR SPIDERMAN MOVIE
   int id_spiderman_gold;
   int id_spiderman_sil;
   int id_sadak2_pt; //booking id of the customerFOR SADAK WMOVIE
   int id_sadak2_gold;
   int id_sadak2_sil;
   int id_singham_pt;//booking id of the customerFOR SINGHAM MOVIE
   int id_singham_gold;
   int id_singham_sil;
   int movie_choice;// TO STORE THE CHOICE OF MOVIE
   int lang_choice; //to store the choice of the language
};
int main()
{
    struct theatre th; //object of structure
    struct theatre th1; //object of structure specially for display function
    th.id_avenger_pt=1000;
    th.id_avenger_gold=1001;
    th.id_avenger_sil=1002;
    th.id_spiderman_pt=2000;
    th.id_spiderman_gold=2001;
    th.id_spiderman_sil=2002;
    th.id_sadak2_pt=3000;
    th.id_sadak2_gold=3001;
    th.id_sadak2_sil=3002;
    th.id_singham_pt=4000;
    th.id_singham_gold=4001;
    th.id_singham_sil=4002;
    th.movie_choice=0;
    th.lang_choice=0;
    int choice;
    do
    {
    printf("\n\n\n");
    SetColor(9);
	printf("                          Movie Ticket Booking System\n"                              );
	printf("||===============================================================================||\n");
	printf("||                 1- To edit price of ticket (only admin):                      ||\n");
	printf("||                 2- To purchase ticket:                                        ||\n");
	printf("||                 3- To cancel the ticket:                                      ||\n");
	printf("||                 4- To view the details of the ticket booked:                  ||\n");
	printf("||                 5- Exit the system                                            ||\n");
	printf("||===============================================================================||\n");
	printf("  Enter your choice: ");
	scanf("%d",&choice);
   switch(choice)
   {
	case 1: // Changing the price (Only done by admin)
    {
        int choice1;
        printf("\n1.Platinum seat\n2.Gold seat\n3.Silver seat\nEnter the seat type of whose you want to edit the price: ");
        scanf("%d",&choice1);
        if(choice1==1)
        {
            printf("\nOld price: %d",platinum_price);
            platinum_price=editing_admin(platinum_price);
            printf("\nNew price: %d",platinum_price);
        }
        else if(choice1==2)
        {
            printf("\nOld price: %d",gold_price);
            gold_price=editing_admin(gold_price);
            printf("\nNew price: %d",gold_price);
        }
        else if(choice1==3)
        {
            printf("Old price: %d",silver_price);
            silver_price=editing_admin(silver_price);
            printf("\nNew price: %d",silver_price);
        }
        else
        {
            printf("\nInvalid type of seat entered");
        }
        break;
    }
    case 2:  // purchasing the ticket
    {
        printf("\nPlease enter your first name: ");
       scanf("%s",&f_name);
       printf("\nPlease enter your last name: ");
        scanf("%s",&l_name);
        purchasing(th);
        break;
    }
   case 3://CANCELLING TICKET
    {
         cancel(th); //IF PURCHASED A TICKET,SOME VALUE IS PASSED IF NOT 0 IS PASSED
        break;
    }

    case 4:
    {
       details(th);
        break;
    }
    case 5:
    {
        SetColor(2);
        printf("Thank you!\n");
        printf("Made by:\n");
        printf("Aryan Irani C033\nVihaan Jadhav C035\nVitrag Khatadia C047");
        exit(0);
        break;
    }
   default:
    {
                SetColor(4);
        printf("\nInvalid Choice");
        exit(0);
      break;
    }

}
    }
while(choice!=5);
}
int editing_admin(int temp) // Changing the password (Only by admin)
{
    char pass[100]={ 0 };
    int i;
    pre_pass:
    printf("\n Enter the password to change the price of the ticket:\n");
    for (i = 0; i <11;i++)
    {
        pass[i] = _getch(); _putch('*');
        if (pass[i] == 11)
        break;
    }
    if(strcmp(pass,pre_pass)==0)
    {
        printf("\nPlease enter new price: ");
		scanf("%d",&temp);
    }
    else
    {
        SetColor(4);
        printf("\nThe password entered is wrong");
        goto pre_pass;
    }
    return temp;
}
int purchasing(struct theatre th)
{
    int seat_i,seat_j;
    int i,j,x,y;  //i,x = english    j,y= hindi
    int lang;
    printf("\n\nMovie type: Hollywood or Bollywood \n");
    printf("Press 1 for Hollywood  \n");
    printf("Press 2 for Bollywood  \n");
    printf("Enter your choice: ");
    scanf("%d", &lang);
    //movie_lang=lang;
    if(lang == 1)
    {
    printf("\t\t\tWhich movie you want to see?\n");

    for(i = 1;i<=1;i++)
    {
	  printf("\t\t\t----------------------------\n\n"      );
	  printf("\t\t\t Press %d for Avengers: EndGame\n\n",i       );
	  printf("\t\t\t Press %d for Spider-Man: Far From Home\n", i+1);
        }
    printf("Enter your choice: ");
    scanf("%d",&x);
    th.movie_choice=x;
    switch(x)
    {
      case 1:
          {
        if(top_avenger==max_avenger-1)
        {
            printf("HOUSEFULL");
            break;
        }
       else
       {
            selection_seat_fn(avenger_stck[top_avenger]);
           if (selection_seat2>10&&selection_seat2<16)
           {
               avenger_plt_seat();
           }
           else if (selection_seat2>5&&selection_seat2<11)
           {
               avenger_gold_seat();
           }
           else
           {
               avenger_sil_seat();
           }
           top_avenger++;
           avenger_stck[top_avenger]=selection_seat2;
           top_f_name_avenger++;
           strcpy(stck_f_name_avenger[top_f_name_avenger],f_name);
           top_l_name_avenger++;
              strcpy(stck_l_name_avenger[top_l_name_avenger],l_name);
              top_bookingid_avenger++;
              bookingid_avenger[top_bookingid_avenger]=bookingid_final;
       }

       //food_wish(th,th1);
       ticket_avenger(th);
       break;
          }
     case 2:
         {
         if(top_spiderman==max_spiderman)
        {
            printf("HOUSEFULL");
            break;
        }
       else
       {
           selection_seat_fn(spiderman_stck[top_spiderman]);
           if (selection_seat2>10&&selection_seat2<16)
           {
               spiderman_plt_seat();
           }
           else if (selection_seat2>5&&selection_seat2<11)
           {
               spiderman_gold_seat();
           }
           else
           {
               spiderman_sil_seat();
           }
           top_spiderman++;
           spiderman_stck[top_spiderman]=selection_seat2;
           top_f_name_spiderman++;
           strcpy(stck_f_name_spiderman[top_f_name_spiderman],f_name);
           top_l_name_spiderman++;
              strcpy(stck_l_name_spiderman[top_l_name_spiderman],l_name);
               top_bookingid_spiderman++;
              bookingid_spiderman[top_bookingid_spiderman]=bookingid_final;
       }

       ticket_spiderman(th);
       break;}
    }
    }
    else if(lang == 2)
    {
    printf("\t\t\tWhich movie you want to see?\n");
    for(j = 1;j<=1;j++)
    {
	   printf("\t\t\t----------------------------\n\n" );
	   printf("\t\t\t %d for Singham   \n\n", j    );
	   printf("\t\t\t %d for Sadak2   \n", j+1        );
    }
    printf("Enter your choice: ");
    scanf("%d",&y);
    th.movie_choice=y;
    switch(y)
    {
         case 1:
        if(top_singham==max_singham-1)
        {
            printf("HOUSEFULL");
            break;
        }
       else
       {
           selection_seat_fn(singham_stck[top_singham]);
           if (selection_seat2>10&&selection_seat2<16)
           {
               singham_plt_seat();
           }
           else if (selection_seat2>5&&selection_seat2<11)
           {
              singham_gold_seat();
           }
           else
           {
               singham_sil_seat();
           }
           top_singham++;
           singham_stck[top_singham]=selection_seat2;
           top_f_name_singham++;
           strcpy(stck_f_name_singham[top_f_name_singham],f_name);
           top_l_name_singham++;
              strcpy(stck_l_name_singham[top_l_name_singham],l_name);
               top_bookingid_singham++;
              bookingid_singham[top_bookingid_singham]=bookingid_final;
       }
      // food_wish(th,th1);
       ticket_singham(th);
       break;
     case 2:if(top_sadak2==max_sadak2)
        {
            printf("HOUSEFULL");
            break;
        }
       else
       {
           selection_seat_fn(sadak2_stck[top_sadak2]);
                      if (selection_seat2>10&&selection_seat2<16)
           {
               sadak2_plt_seat();
           }
           else if (selection_seat2>5&&selection_seat2<11)
           {
              sadak2_gold_seat();
           }
           else
           {
               sadak2_sil_seat();
           }
           top_sadak2++;
           sadak2_stck[top_sadak2]=selection_seat2;
           top_f_name_sadak2++;
           strcpy(stck_f_name_sadak2[top_f_name_sadak2],f_name);
           top_l_name_sadak2++;
              strcpy(stck_l_name_sadak2[top_l_name_sadak2],l_name);
               top_bookingid_sadak2++;
              bookingid_sadak2[top_bookingid_sadak2]=bookingid_final;
       }
       ticket_sadak2(th);
       break;
    }
    }
    else
    {
        printf("Wrong Input");
    }
    th.lang_choice=lang;
}
  int selection_seat_fn(int x)
     {
      int seat_i,seat_j;
       int i,j;
    printf("\n\n\t\tSCREEN\n");
    int cn=1; //for seats
    for(seat_i=1;seat_i<4;seat_i++)
    {
        for(seat_j=1;seat_j<6;seat_j++)
        {
            if (cn==x)
            {
                printf("BOOKED\t");
                cn++;
            }
          else {
            printf("%d\t",cn);
            cn++;
        }
        }
    printf("\n");
    }
    int choice2;
        printf("\n\nPlease choose your seat type:");
        printf("\n1.Platinum seat(11-15) Price:%d \n2.Gold seat(6-10) Price:%d\n3.Silver seat(1-5) Price:%d\nEnter the choice of your seat: ",platinum_price,gold_price,silver_price);
        scanf("%d",&choice2);
        switch(choice2 )
        {
        case 1:
            {
            printf("\nPlease enter your desired seat number from the above layout: ");
            scanf("%d",&selection_seat2);

          if(selection_seat2<16&&selection_seat2>10)

            {
               printf("...");
            }

            else{
                            SetColor(4);
                printf("NOT VALID SEAT NO ");
                exit(0);
            }break;
        }
        case 2:
        {
            printf("\nPlease enter your desired seat number from the above layout: ");
            scanf("%d",&selection_seat2);

            if(selection_seat2<11&&selection_seat2>5)
            printf("...");
            else{
                    SetColor(4);
             printf("NOT VALID SEAT NO");
             exit(0);
            }
            break;
        }
       case 3:
        {
             printf("\nPlease enter your desired seat number from the above layout: ");
            scanf("%d",&selection_seat2);

            if(selection_seat2<6&&selection_seat2>0)
          printf("Price: %d",silver_price);
            else{
                    SetColor(4);
             printf("NOT VALID SEAT NO");
             exit(0);
            }break;
        }
        default:
        {
            printf("Invalid");
            exit(0);
            break;
        }
        return selection_seat2;
    }
        }
void avenger_plt_seat()
{
      if(top_avenger_pt==max_avengerplt_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR PLATINUM AVAILABLE");
            exit(0);
        }
       else
       {
           bookingid_final=1000;
           top_avenger_pt++;
           avenger_stck_pt[top_avenger_pt];
           }
}
void avenger_gold_seat()
{
 if(top_avenger_gold==max_avengergold_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR GOLD AVAILABLE");
            exit(0);
        }
       else
       {
            bookingid_final=1001;
         top_avenger_gold++;
           avenger_stck_gold[top_avenger_gold];
           }
}
void avenger_sil_seat()
{
 if(top_avenger_sil==max_avengersil_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR SILVER AVAILABLE");
            exit(0);
        }
       else
       {
            bookingid_final=1002;
           top_avenger_sil++;
           avenger_stck_sil[top_avenger_sil];
               }
}
void spiderman_plt_seat()
{
      if(top_spiderman_pt==max_spidermanplt_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=2000;
           top_spiderman_pt++;
           spiderman_stck_pt[top_spiderman_pt];
           }
}
void spiderman_gold_seat()
{
 if(top_spiderman_gold==max_spidermangold_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=2001;
         top_spiderman_gold++;
        spiderman_stck_gold[top_spiderman_gold];
           }
}
void spiderman_sil_seat()
{
 if(top_spiderman_sil==max_spidermansil_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=2002;
           top_spiderman_sil++;
           spiderman_stck_sil[top_spiderman_sil];
               }
}
void singham_plt_seat()
{
      if(top_singham_pt==max_singhamplt_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=4000;
           top_singham_pt++;
           singham_stck_pt[top_singham_pt];
           }
}
void singham_gold_seat()
{
 if(top_singham_gold==max_singhamgold_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=4001;
         top_singham_gold++;
           singham_stck_gold[top_singham_gold];
           }
}
void singham_sil_seat()
{
 if(top_singham_sil==max_singhamsil_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=4002;
           top_singham_sil++;
           singham_stck_sil[top_singham_sil];
               }
}
void sadak2_plt_seat()
{
      if(top_sadak2_pt==max_sadak2plt_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=3000;
           top_sadak2_pt++;
           sadak2_stck_pt[top_sadak2_pt];
           }
}
void sadak2_gold_seat()
{
 if(top_sadak2_gold==max_sadak2gold_seat-1)
        {
             bookingid_final=3001;
             SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=3001;
         top_sadak2_gold++;
           sadak2_stck_gold[top_sadak2_gold];
           }
}
void sadak2_sil_seat()
{
 if(top_sadak2_sil==max_sadak2sil_seat-1)
        {
            SetColor(4);
            printf("NO TICKET AVAILBLE FOR THIS");
            exit(0);
        }
       else
       {
            bookingid_final=3002;
           top_sadak2_sil++;
          sadak2_stck_sil[top_sadak2_sil];
               }
}
int cancel(struct theatre th)
{
    int lang_ch; //local for comparing language
    int movie_ch;//local for comparing movie
    int book_id;
    int lang;// local variable for comparing with real
    lang_ch=th.lang_choice;
    movie_ch=th.movie_choice;
    printf("\n\nEnter the movie type of whose you want to cancel the ticket: Hollywood or Bollywood \n");
    printf("Press 1 for Hollywood  \n");
    printf("Press 2 for Bollywood  \n");
    printf("Enter: ");
    scanf("%d", &lang);
    if(lang==1)
    {
        int choice_hollywood;
        printf("Which movie ticket you want to cancel? \n");
        printf("\n1.Avengers: EndGame\n\n"       );
	    printf("\n2.Spider-Man: Far From Home\n");
	     printf("Please enter your choice- \n");
	    scanf("%d",&choice_hollywood);
	    if(choice_hollywood==1)
        {
               if (top_avenger==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
    printf("Enter booking id:\t");
    scanf("%d",&book_id);
    if(book_id<=th.id_avenger_sil&&book_id>=th.id_avenger_pt)
    {
    if(book_id==th.id_avenger_pt){
    if (top_avenger_pt==-1)
        {
            SetColor(4);
            printf("NO TICKET PURCHASED YET");}
    else{
    top_avenger_pt--;
    SetColor(4);
    printf("TICKET FOR AVENGER FOR BOOKING ID %d IS CANCELED ",th.id_avenger_pt);
    top_f_name_avenger--;
    top_l_name_avenger--;
     top_avenger--;
     top_bookingid_avenger--;
    }
    }
    else if(book_id==th.id_avenger_gold){
            if (top_avenger_gold==-1)
            {
                SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_avenger_gold--;
    SetColor(4);
    printf("TICKET FOR AVENGER FOR BOOKING ID %d IS CANCELED ",th.id_avenger_gold);
      top_f_name_avenger--;
    top_l_name_avenger--;
    top_avenger--;
    top_bookingid_avenger--;
    }
    }
     else{
            if (top_avenger_sil==-1)
            {
                SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_avenger_sil--;
    SetColor(4);
    printf("TICKET FOR AVENGER FOR BOOKING ID %d IS CANCELED ",th.id_avenger_sil);
      top_f_name_avenger--;
    top_l_name_avenger--;
     top_avenger--;
     top_bookingid_avenger--;
    }
    }}
    else
    {
        SetColor(4);
        printf("WRONG ID");
    }

   }
        }
    else if(choice_hollywood==2)
        {
               if (top_spiderman==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
    printf("Enter booking id:\t");
    scanf("%d",&book_id);
    if(book_id<=th.id_spiderman_sil&&book_id>=th.id_spiderman_pt)
    {
    if(book_id==th.id_spiderman_pt){
    if (top_spiderman_pt==-1)
        {
            SetColor(4);
            printf("NO TICKET PURCHASED YET");}
    else{
    top_spiderman_pt--;
    SetColor(4);
    printf("TICKET FOR SPIDERMAN FOR BOOKING ID %d IS CANCELED ",th.id_spiderman_pt);
      top_f_name_spiderman--;
    top_l_name_spiderman--;
    top_spiderman--;
    top_bookingid_spiderman--;
    }
    }
    else if(book_id==th.id_spiderman_gold){
            if (top_spiderman_gold==-1)
                {
                    SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_spiderman_gold--;
    SetColor(4);
    printf("TICKET FOR SPIDERMAN FOR BOOKING ID %d IS CANCELED ",th.id_spiderman_gold);
      top_f_name_spiderman--;
    top_l_name_spiderman--;
     top_spiderman--;top_bookingid_spiderman--;
    }
    }
     else  {
            if (top_spiderman_sil==-1)
            {
                SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_spiderman_sil--;
    SetColor(4);
    printf("TICKET FOR SPIDERMAN FOR BOOKING ID %d IS CANCELED ",th.id_spiderman_sil);
      top_f_name_spiderman--;
    top_l_name_spiderman--;
     top_spiderman--;top_bookingid_spiderman--;
    }
    }
    }
    else
    {
        SetColor(4);
        printf("WRONG ID");
    }

   }
        }
    }
    else if (lang==2)
    {
        int choice_bollywood;
        printf("Which movie ticket you want to cancel \n");
        printf("\n1. Singham \n\n"       );
	    printf("\n2. Sadak2 \n\n");
	    scanf("%d",&choice_bollywood);

            if(choice_bollywood==1)
        {
               if (top_singham==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
    printf("Enter booking id: ");
    scanf("%d",&book_id);
    if(book_id<=th.id_singham_sil&&book_id>=th.id_singham_pt)
    {
    if(book_id==th.id_singham_pt){
    if (top_singham_pt==-1)
        {
            SetColor(4);
            printf("NO TICKET PURCHASED YET");}
    else{
    top_singham_pt--;
    SetColor(4);
    printf("TICKET FOR SINGHAM FOR BOOKING ID %d IS CANCELED ",th.id_singham_pt);
      top_f_name_singham--;
    top_l_name_singham--;
     top_singham--;top_bookingid_singham--;
    }
    }
    else if(book_id==th.id_singham_gold){
            if (top_singham_gold==-1)
                {
                    SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_singham_gold--;
    SetColor(4);
    printf("TICKET FOR SINGHAM FOR BOOKING ID %d IS CANCELED ",th.id_singham_gold);
        top_f_name_singham--;
    top_l_name_singham--;
    top_singham--;top_bookingid_singham--;
    }
    }
     else  {
            if (top_singham_sil==-1)
                {
                    SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_singham_sil--;
    SetColor(4);
    printf("TICKET FOR SINGHAM FOR BOOKING ID %d IS CANCELED ",th.id_singham_sil);
        top_f_name_singham--;
    top_l_name_singham--;
    top_singham--;top_bookingid_singham--;
    }
    }}
    else
    {
        SetColor(4);
        printf("WRONG ID");
    }

   }
        }
        	 else if(choice_bollywood==2)
        {
               if (top_sadak2==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
    printf("ENTER BOOKING ID");
    scanf("%d",&book_id);
    if(book_id<=th.id_sadak2_sil&&book_id>=th.id_sadak2_pt)
    {
    if(book_id==th.id_sadak2_pt){
    if (top_sadak2_pt==-1)
        {
            SetColor(4);
            printf("NO TICKET PURCHASED YET");}
    else{
    top_sadak2_pt--;
    SetColor(4);
    printf("TICKET FOR SADAK2 FOR BOOKING ID %d IS CANCELED ",th.id_sadak2_pt);
        top_f_name_sadak2--;
    top_l_name_sadak2--;
    top_sadak2--;top_bookingid_sadak2--;
    }
    }
    else if(book_id==th.id_sadak2_gold){
            if (top_sadak2_gold==-1)
                {
                    SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_sadak2_gold--;
    SetColor(4);
    printf("TICKET FOR SADAK2 FOR BOOKING ID %d IS CANCELED ",th.id_sadak2_gold);
        top_f_name_sadak2--;
    top_l_name_sadak2--;
    top_sadak2--;top_bookingid_sadak2--;
    }
    }
     else  {
            if (top_sadak2_sil==-1)
                {
                    SetColor(4);
                    printf("NO TICKET PURCHASED YET");}
    else{
    top_sadak2_sil--;
    SetColor(4);
    printf("TICKET FOR SADAK2 FOR BOOKING ID %d IS CANCELED ",th.id_sadak2_sil);
        top_f_name_sadak2--;
    top_l_name_sadak2--;
    top_sadak2--;top_bookingid_sadak2--;
    }
    }}
    else
    {
        SetColor(4);
        printf("WRONG ID");
    }

   }
        }
else
{
    SetColor(4);
    printf("Error");
}
}
else{printf("ERROR");}
}
void details(struct theatre th)
{
   int booking_id;
   printf("\nEnter booking ID of the movie to see the details: ");
   scanf("%d",&booking_id);
  if(booking_id<=th.id_avenger_sil&&booking_id>=th.id_avenger_pt)
   {
       ticket_avenger();
   }
   else if(booking_id<=th.id_spiderman_sil&&booking_id>=th.id_spiderman_pt)
   {
       ticket_spiderman();
   }
   else if(booking_id<=th.id_sadak2_sil&&booking_id>=th.id_sadak2_pt)
   {
       ticket_sadak2();
   }
   else if(booking_id<=th.id_singham_sil&&booking_id>=th.id_singham_pt)
   {
       ticket_singham();
   }
   else
   {
       SetColor(4);
       printf("\nPlease enter a valid Booking ID to see the details");
   }
}
void ticket_avenger(struct theatre th)
{
        int localprice;
        if(avenger_stck[top_avenger]>=11 && avenger_stck[top_avenger]<=15)
        {
          localprice=platinum_price;
        }
        else if(avenger_stck[top_avenger]>=6 && avenger_stck[top_avenger]<=10)
        {
         localprice=gold_price;
        }
        else
         {
             localprice=silver_price;
         }
           if (top_avenger==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else {
		printf("\n\n\n\n");
		SetColor(14);
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n",bookingid_avenger[top_bookingid_avenger]);
        printf("\t Customer details:\nFirst name:%s\n",stck_f_name_avenger[top_f_name_avenger]);
        printf("\t\nLast name:%s\n",stck_l_name_avenger[top_l_name_avenger]);
        printf("\t\t\t                              Date      : 20-10-2020\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 01\n");
        printf("\t                                              Seats No. : %d  \n",avenger_stck[top_avenger]);
        printf("\t                                              Price . : %d  \n\n",localprice);
        printf("\t============================================================\n");
        return;
}
}
void ticket_spiderman(struct theatre th)
{
        int localprice;
     if(spiderman_stck[top_spiderman]>=11 && spiderman_stck[top_spiderman]<=15)
        {
         localprice=platinum_price;
        }
        else if(spiderman_stck[top_spiderman]>=6 && spiderman_stck[top_spiderman]<=10)
        {
         localprice=gold_price;
        }
        else
         {
             localprice=silver_price;
         }
             if (top_spiderman==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
		printf("\n\n\n\n");
		SetColor(14);
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home\n",bookingid_spiderman[top_bookingid_spiderman]);
        printf("\t Customer details:\nFirst name:%s\n",stck_f_name_spiderman[top_f_name_spiderman]);
        printf("\t\nLast name:%s\n",stck_l_name_spiderman[top_l_name_spiderman]);
        printf("\t\t\t                              Date      : 20-10-2020\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              Seats No. : %d  \n",spiderman_stck[top_spiderman]);


        printf("\t                                              Price . : %d  \n\n",localprice);
        printf("\t============================================================\n");
        return;
}
}
void ticket_sadak2(struct theatre th)
{
    int localprice;
     if(sadak2_stck[top_sadak2]>=11 && sadak2_stck[top_sadak2]<=15)
        {
         localprice=platinum_price;
        }
        else if(sadak2_stck[top_sadak2]>=6 && sadak2_stck[top_sadak2]<=10)
        {
         localprice=gold_price;
        }
        else
         {
             localprice=silver_price;
         }
             if (top_sadak2==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
		printf("\n\n\n\n");
		SetColor(14);
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Sadak 2\n",bookingid_sadak2[top_bookingid_sadak2]);
        printf("\t Customer details:\nFirst name:%s\n",stck_f_name_sadak2[top_f_name_sadak2]);
        printf("\t\nLast name:%s\n",stck_l_name_sadak2[top_l_name_sadak2]);
        printf("\t\t\t                              Date      : 20-10-2020\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              Seats No. : %d  \n",sadak2_stck[top_sadak2]);
        printf("\t                                              Price . : %d  \n\n",localprice);
        printf("\t============================================================\n");
        return;
}}
void ticket_singham(struct theatre th)
{
        int localprice;
     if(singham_stck[top_singham]>=11 &&singham_stck[top_singham]<=15)
        {
         localprice=platinum_price;
        }
        else if(singham_stck[top_singham]>=6 && singham_stck[top_singham]<=10)
        {
         localprice=gold_price;
        }
        else
         {
             localprice=silver_price;
         }
             if (top_singham==-1)
   {
       SetColor(4);
       printf("NO TICKET IS PURCHASED YET");
   }
   else{
		printf("\n\n\n\n");
		SetColor(14);
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Singham\n",bookingid_singham[top_bookingid_singham]);
        printf("\t Customer details:\nFirst name:%s\n",stck_f_name_singham[top_f_name_singham]);
        printf("\t\nLast name:%s\n",stck_l_name_singham[top_l_name_singham]);
        printf("\t\t\t                              Date      : 20-10-2020\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              Seats No. : %d  \n",singham_stck[top_singham]);
        printf("\t                                              Price . : %d  \n\n",localprice);
        printf("\t============================================================\n");
        return;
}}
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
