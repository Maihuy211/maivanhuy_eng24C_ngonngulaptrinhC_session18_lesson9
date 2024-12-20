# include<stdio.h>
# include <string.h>
int main(){
	struct Dish{
		int id;
		char name[50];
		float price;
	};
	struct Dish menu[100]={
		{1,"sushi",3.15},
		{2,"ramen",10.15},
		{3,"Tempura",9.60},
		{4,"sup miso",5.50},
		{5,"sashimi",15.75}	
	};
	int choice;
	int n=5;
	do{
		printf("\nMenu\n");
		printf("1.In ra gia tri cac phan tu co trong menu\n");
		printf("2.Them mot phan tu vao vi tri chi dinh\n");
		printf("3.Sua mot phan tu o vi tri chi dinh\n");
		printf("4.xoa mot phan tu o vi tri chi dinh\n");
		printf("5.Sap xep cac phan tu\n");
		printf("6.Tim kiem phan tu theo name nhap vao\n");
		printf("7.Thoat\n");
		printf("nhap lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			int i;
			case 1:
				printf("cac phan tu co trong mang la: \n");
				for(i=0;i<n;i++){
					printf("%d.%s. %.2f\n",menu[i].id,menu[i].name,menu[i].price);
				}
			    break;
		    int pos;
			case 2:
				printf("them phan tu vao vi tri: ");
		        scanf("%d",&pos);
		        struct Dish newfood;
		        newfood.id=n+1;
				fflush(stdin);
                printf("nhap ten mon an moi: ");
                fgets(newfood.name,sizeof(newfood.name),stdin);
				newfood.name[strcspn(newfood.name,"\n")]='\0';
				printf("nhap gia cua mon an moi: ");
				scanf("%f",&newfood.price);
			    if(pos<0||pos>n){
			    	printf("ko hop le");
				}else{
					for(i=n;i>pos;i--){
		    		    menu[i]=menu[i-1];
			        }
			        menu[pos]=newfood;
			        n++;
				}
				break;
			case 3:
				printf("sua phan tu o vi tri: ");
		        scanf("%d",&pos);
			    if(pos<0||pos>=n){
			    	printf("ko hop le");
				}
				fflush(stdin);
				printf("nhap lai ten mon an can sua: ");
				fgets(menu[pos].name, sizeof(menu[pos].name), stdin);
                menu[pos].name[strcspn(menu[pos].name, "\n")] = '\0';
                printf("nhap lai gia cua mon an can sua: ");
                scanf("%f", &menu[pos].price);
				break;
			case 4:
				printf("xoa phan tu vao vi tri: ");
		        scanf("%d",&pos);
			    if(pos<0||pos>=n){
			    	printf("ko hop le");
				}else{
					for(i=pos;i<n-1;i++){
		    		    menu[i]=menu[i+1];
			        }
			        n--;
				}
				break;
		    int choice2;
		    case 5:
		    	do{
		    		printf("\nsap xep cac phan tu\n");
		    		printf("1.giam dan theo price\n");
		    		printf("2.tang dan theo price\n");
		    		printf("3.thoat\n");
		    		printf("nhap lua chon cua ban: ");
		    		scanf("%d",&choice2);
					int i,j;
					switch(choice2){
						case 1:
							printf("cac mon an sap xep giam dan theo gia la\n");
							for(i=0;i<n;i++){
    		    	            for(j=0;j<n-i-1;j++){
    		    		            if(menu[j+1].price<menu[j].price){
			    		    			float temp=menu[j].price;
			    		    			menu[j].price=menu[j+1].price;
			    		    			menu[j+1].price=temp;
						            }
					            }
				            }
						    for(i=0;i<n;i++){
					            printf("%d.%s. %.2f\n",menu[i].id,menu[i].name,menu[i].price);
				            }
			                break;
			            case 2:
			            	printf("cac mon an sap xep tang dan theo gia la\n");
							for(i=0;i<n;i++){
    		    	            for(j=0;j<n-i-1;j++){
    		    		            if(menu[j+1].price>menu[j].price){
			    		    			int temp=menu[j].price;
			    		    			menu[j].price=menu[j+1].price;
			    		    			menu[j+1].price=temp;
						            }
					            }
				            }
						    for(i=0;i<n;i++){
					            printf("%d.%s. %.2f\n",menu[i].id,menu[i].name,menu[i].price);
				            }
			                break;
			            case 3:
			            	break;
			            default:
			            	printf("lua chon ko hop le nhap lai");	
					}				
				}while(choice2!=3);
				break;
			case 6:
				do{
					printf("\ntim kiem phan tu theo name nhap vao\n");
		    		printf("1.Tim kiem tuyen tinh\n");
		    		printf("2.Tim kiem nhi phan\n");
		    		printf("3.thoat\n");
		    		printf("nhap lua chon cua ban: ");
		    		scanf("%d",&choice2);
					int check;
					char search[50];
					switch(choice2){
						case 1:
							fflush(stdin);
							printf("moi ban nhap mon can tim: ");
							fgets(search,sizeof(search),stdin);
							search[strcspn(search,"\n")]='\0';
							check=-1;
							for(i=0;i<n;i++){
								if(strcmp(menu[i].name,search)==0){
									check=i;
									break;
								}
							}
							if(check==-1){
								printf("khong co mon nay trong menu");
							}else{
								printf("mon %s la mon thu %d trong menu",search,menu[i].id);
							}
							break;
						int start,end,mid;
						int i,j;
						char search[50];
						case 2:
							for (i=0;i<n-1;i++){
								for (j=0;j<n-i-1;j++){
									if(strcmp(menu[j + 1].name, menu[j].name)<0){
										struct Dish temp = menu[j];
										menu[j] = menu[j + 1];
										menu[j + 1] = temp;
									}
								}
							}
							fflush(stdin);
							printf("Moi ban nhap mon can tim: ");
							fgets(search, sizeof(search), stdin);
							search[strcspn(search, "\n")] = '\0';
							start = 0;
							end = n - 1;
							check = -1;
							while (start<=end){
								mid = (start + end) / 2;
								if (strcmp(menu[mid].name, search)==0){
									check = mid;
									break;
								}
								else if (strcmp(menu[mid].name, search)>0){
									end=mid-1;
								}
								else{
									start=mid+1;
								}
							}
							if(check==-1){
								printf("khong co mon nay trong menu");
							}else{
								printf("mon %s la mon thu %d trong menu",search,menu[i].id);
							}
							break;
						case 3:
							break;
						default:
						    printf("lua chon ko hop le nhap lai");
				    }
				}while(choice2!=3);
				break;
			default:
			    printf("lua chon khong hop le (moi nhap lai)");		
        }
	}while(choice!=7);
    return 0;	
}
