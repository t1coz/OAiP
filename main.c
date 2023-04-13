/*
 * 1 LECTURE
 * --------------------------------------------------------------------------------------------------------------------
 *FILE *fp;
 * fp = fopen("path/fileName", "mode");                    -1 if not found (NULL)
 * fclose(FILE *fp);
 * feof();
 * freopen(); --- reopen
 * fflush();
 * ferror();
 * remove();  --- to delete the file
 * fprintf(); fscanf();
 * SEEK_SET, SEEK_CUR, SEEK_END
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 2 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 * fread, fseek, ftell, fwrite
 * sort, deletion
 * photots from the screen
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 3 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 * typedef struct Point POINT; (first variation)
 * complex structures:
 *  gr[1].list[4].surname[2];
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 4 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 *(*(STUD + i)).fio = calloc
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 5 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 * structures and how to work with them
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 6 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 * lists and other stuff
 * struct list{
 *  char info;
 *  list *ptr
 * };
 *
 * stacks:
 * struct filo{
 *  char info;
 *  filo *next
 * };
 *
 * filo* push(filo *head, char n){
 *  filo *temp = (filo*)calloc(1, sizeof(filo));
 *  temp->info = n;
 *  temp->next = NULL;
 *  if(head == NULL){
 *      head = temp;
 *  }else{
 *      temp->next = head;
 *      head = temp;
 *  }
 *  return head;
 * }
 * (((in main set head to NULL)))
 *
 * filo* pop(filo *head, char n){
 *  if(head != NULL){
 *   filo *temp = head;
 *   head = head->next;
 *   free(temp);
 *  }
 *  return *head;
 * }
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 7 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 * pop and push from previous lecture;
 * merge sorting
 * FILO* output_ASC(FILO* h){
 *      char choice = 'y';
 *      int num;
 *      while(choice = 'y'){
 *          printf("Enter the number: ");
 *          scanf("d", &num);
 *          if(ASC_order(h, num) == 1){
 *              push(&h, num);
 *              printf("Do you want to continue?: y/n");
 *              scanf("%c", &choice);
 *              continue;
 *          }else{
 *              printf("Try again.");
 *              continue;
 *          }
 *      }
 *      return h;
 * }
 * int ASC_order(FILO*h, int num){
 *      if(n!=NULL && h->data > num){
 *          if(num < n->head){
 *              return 1;
 *          }else{
 *              return 1;
 *          }
 *      }
 *      return 0;
 * }
 * int size_FILO(FILO* h){
 *      int size = 0;
 *      FILO* temp = h;
 *      while(temp != NULL){
 *          size++;
 *          temp = temp->next;
 *      }
 *      return size;
 * }
 * FILO* n_m_FILO(FILO* head, int n){
 *      int t = n-1;
 *      FILO* temp = head;
 *      while(t && temp != NULL){
 *          temp = temp->next;
 *          t--;
 *      }
 *      return temp;
 * }
 * FILO* mergeFilo_ASC(FILO* h1, FILO* h2, FILO* h3, int size){
 *      int n =  size_FILO(h1)-1;
 *      FILO* temp2 = h2;
 *      while(temp != NULL && h != 0){
 *          FILO* temp1 = n_m_FILO(h1, n);
 *          if(temp2->data > temp1->data){
 *              push(&h3, temp2->data);
 *              pop(temp2);
 *          }else{
 *              push(&h3, temp1->data);
 *              n--;
 *          }
 *      }
 *      if(temp2 == NULL){
 *          while(n!=0){
 *              FILO* temp = n_m_FILO(h1, n);
 *              push(&h3, temp1->data);
 *              n--;
 *          }
 *      }else{
 *          while(temp2!=NULL){
 *              push(&h3, temp2->data);
 *              pop(&temp2, n);
 *          }
 *      }
 *      return h3;
 * }
 * --------->
 * head1, head2, head3;
 * head1 = output_ASC(head1);
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 8 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 *
 * reversed polish notation
 * +- - 1
 * /(*)/ - 2
 * ( - 3
 * ) -
 *
 * 2+3  -->  23+
 * 2+3-4 --> 23+4
 * 2+3*4 --> 234*+
 * 2+3*4*5 --> 234*5*+4-
 * 2+3/4*5-4 --> 234/5*+4-
 * 2+(3-4)*5-4 --> 234-5*+4-
 *
 * 2+(3-4*5+6)-7/2*(1+2+(3*4+5*6*7*8)+9)
 *
 * --------------------------------------------------(((queue)))
 * 
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 8 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 *
 * void pop(FIFO**h, FIFO**t){
 *      FIFO* temp = *h;
 *      if(*h == *t){
 *          *h = NULL;
 *          *t = NULL;
 *      }else{
 *          *h = *h->next;
 *      }
 *      free(temp);
 * }
 *
 * ------------------------------------------------(((Doubly linked list)))
 * void pushHead(Deq** h, Deq**t, int num){
 *      Deq* temp = realloc();
 *      temp->next = NULL;
 *      temp->prev = NULL;
 *      temp->data = num;
 *      if(*h == NULL){
 *          *h = temp;
 *          *t = temp;
 *      }else{
 *          temp->next = *h;
 *          *h->prev = temp;
 *          *h = temp;
 *      }
 * }
 * void popHead(Deq** h, Deq**t){
 *      (((like pop in )))
 * }
 *
 * --------------------------------------------------------------------------------------------------------------------
 *
 * 9 Lecture
 * --------------------------------------------------------------------------------------------------------------------
 *
 * struct ring{
 *      int info;
 *      ring *next
 * };
 * -------------------------------/////////////////////------------------------------
 * //void pushBefore(ring **p, int a){
//    ring* temp = calloc(1,sizeof(ring));
//    temp->info = a;
//    temp->next = NULL;
//    if(*p!=NULL){
//        ring *p2 = *p;
//        while(*p2->next != *p){
//            p2 = p2->next;
//        }
//        p2->next = temp;
//        temp->next = *p
//    }
//}
//void popAfter(ring **p){
//    if(*p != NULL){
//        ring* temp = *p->next;
//        if(*p->next == *p){
//            *p = NULL;
//        }
//    }
//    else {
//        *p->next = *p->next->next;
//    }
//    free(temp);
//}
//void popAfter(ring **p){
//    if(*p!=NULL){
//        if(*p == *p-next){
//            ring *temp = *p;
//            free(temp);
//            *p = NULL;
//        }else{
//            ring *p2 = *p;
//            while(p2->next->next != *p){
//                p2 = *p->next;
//            }
//            ring *temp = p2->next;
//            p2->next = *p;
//            free(temp);
//        }
//    }
//}
 ----------------///////////////////////--------------------///////////////////////------
void push(struct Ring** p, int x){
    struct Ring* temp;
    temp = (struct Ring *) calloc (1,sizeof(struct Ring);
    temp->next = NULL;
    temp->data = x;
    if (*p == NULL){
            temp->next = temp;
            *p = temp;
    }else{
        temp->next = (*p)->next;
        (*p)->next = temp;
    }
}
void pop(struct Ring** p){
	if (*p==NULL) {
         printf(“EMPTY\n”);
         return;
    }
	if (*p== (*p)->next){
		free(*p);
		*p = NULL;
	}else{
		Ring* temp;
		temp = (*p)->next;
		(*p)->next = (*p)->next->next;
		free( temp);
	}
}
void print(Ring* p){
    struct Ring* temp = p;
    if (p == NULL)
        printf(“EMPTY\n”);
    else
    do{
        printf(“%3d”, temp->data);
        temp = temp->next;
    }while (temp != p);

    printf(“\n”);
}
---------------------------двунапраленное кольцо------------------------------------------
*/
//void push(struct Ring** p, int x){
//    struct Ring* temp;
//    temp = (struct Ring *) calloc (1,sizeof(struct Ring);
//    temp->next = NULL;
//    temp->prev = NULL;
//    temp->data = x;
//    if (*p == NULL){
//        temp->next = temp;
//        temp->prev = temp;
//        *p = temp;
//    }else{
//        temp->next = (*p)->next;
//        (*p)->next->prev = temp;
//        (*p)->next = temp;
//        temp->prev = *p;
//        *p = temp;
//    }
//}
//void pop(struct Ring** p)
//{
//    if (*p == NULL)
//    {
//        printf(“EMPTY\n”);
//        return ;
//    }
//    if (*p == (*p)->next)
//    {
//        free(*p);
//        *p = NULL;
//    }
//    else
//    {
//        Ring* temp;
//        temp = (*p)->next;
//        (*p)->next = temp->next;
//        temp->next->prev = *p;
//        free(temp);
//    }
//}
//void print_next(Ring* p){
//    struct Ring* temp = p;
//    if (p == NULL) printf(“EMPTY\n”);
//    else
//    do{
//        printf("%d", temp->data);
//        temp = temp->next;
//    } while (temp != p);
//
//    printf("\n");
//}

int main(){

    return 0;
}
