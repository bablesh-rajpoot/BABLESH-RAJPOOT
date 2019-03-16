#include <stdio.h>
#include <stdlib.h>
#include "rlyres.h"
#include "conio2.h"

int main()
{
  int ch ,no;
  add_trains();
  while(1)
      {
          clrscr();

  ch = enterchoice();

 switch(ch)
 {
     case 49 : view_trains();
     textcolor(CYAN);
         printf("\n\nPress Enter to continue :");
         _getch();
         clrscr();
          break ;


     case 50 :{
          book_ticket(get_details());
        textcolor(CYAN);
        printf("\n\nPress Enter to continue");
      _getch();

         break ;
     }
     case 51 :{
         clrscr();
         gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(YELLOW);
gotoxy(1,1);
         printf("Enter ticket no :");
     int nu ;

     while(1){
            textcolor(CYAN);
            scanf("%d",&nu);
      if(nu < 0 )
    {
        gotoxy(20,27);
        textcolor(RED);
        printf("ENTER A VALID TICKET NUMBER");
        _getch();
        fflush(stdin);
        gotoxy(20,27);
        printf("\t \t \t \t \t \b");
        gotoxy(18,1);
        printf("\t\t\t\t \b");
        gotoxy(18,1);
    }
    else if(nu > 0){
     view_ticket(nu);
     break ;
    }
    else if(nu == 0)
        break ;

     }
     break ;
     }
     case 52 : {
         while(1){
         clrscr();
             char mob[12];
             gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(YELLOW);
gotoxy(1,1);

          printf("Enter Mobile no: ");
          textcolor(CYAN);
          fflush(stdin);
          fgets(mob,11,stdin);
         int *pos = strchr(mob,'\n');
          if(pos!=NULL)
            *pos = '\0';
            if(strcmp(mob,"0")!=0){
          int no = search_ticket(&mob);
          if(no == 0){
            printf("Sorry no ticket number is found");
            printf("\n\n press Enter to continue");
            _getch();
          }
          else if(no == -1)
            continue ;
          else{
                textcolor(LIGHTGRAY);
            printf("\nYour ticket number is: %d",no);
             textcolor(CYAN);
             printf("\n\n press Enter to continue");
            _getch();
          break ;
          }
            }
            else if(strcmp(mob,"0")==0)
                break ;
         }
         break ;
     }
     case 53 : view_all_bookings();
     textcolor(CYAN);
     printf("\n\n\nPress Enter to continue");
     _getch();
         break ;
     case 54 : clrscr();
     gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(YELLOW);
gotoxy(1,1);
     printf("Enter train number:");
     textcolor(CYAN);
     char trn[10] ;
     fflush(stdin);
     fgets(trn ,10,stdin );
     int *pos = strchr(trn,'\n');
     if(*pos!=NULL)
        *pos='\0';
        if(trn[0]!='0')
     view_booking(&trn);

         break ;
     case 55 : clrscr() ;
     int no ;
     gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(YELLOW);
gotoxy(1,1);
     printf("Enter Ticket no:");
     textcolor(CYAN);
     scanf("%d",&no);
     textcolor(RED);
     if(no != 0){
     no = cancel_ticket(no);
     if(no == 0)

    printf("\nSorry! no bookings found: ");


     else if(no ==1)

    printf("\nTicket cancel Successfully:");
     textcolor(CYAN);
     printf("\n\nPress Enter to continue:");
     _getch();
     }
          break ;
     case 56 :
         clrscr();
         int np ;
       gotoxy(73,1);
textcolor(GREEN);
printf("Press 0 to go back");
textcolor(YELLOW);
gotoxy(1,1);
char tr[10] ;
printf("Enter train no. to cancel train :");
textcolor(CYAN);
fflush(stdin);
fgets(tr,10,stdin);
int *po = strchr(tr,'\n');
textcolor(LIGHTGRAY);
     if(*po!=NULL)
        *po='\0';
        if(strcmp(tr,"0")!=0){
           np = cancel_train(&tr);
        if(np == 0)
            printf("\nThere are no bookings in this train:");
        else if(np == 1)
            printf("\nTrains bookings are canceled successfully:");
         textcolor(CYAN);
        printf("\n\n\nPress enter to continue:");
        _getch();
        }
         break ;
     case 57 : exit(0);
     break ;
     default :textcolor(LIGHTRED);
         printf("\n\nPlease enter a valid choice!!!!!.... \nTry Again Press Enter");
         _getch();
          clrscr();
     break ;

 }
  }

    return 0 ;
}
