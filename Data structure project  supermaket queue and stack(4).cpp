#include<iostream>
#include<string>
#include <sstream>//is used to rewrite the input in string stream
#include<queue>
#include<stack>
using namespace std;
int search(int);//to search the product by id or to check availablity of product by id for customer
int display();
string check(int);       //   for checking quantity
////////////////////////////////////////////////////////////////////
struct trolies
 {
	int data;
   trolies* link;
   };
struct trolies* top;

void push(int data) //to push number of the trollies for customer
{
	struct trolies* temp;
	temp = new trolies();
	//there is no overflow because we use linked list
    if (!temp) {
		exit(1);
		}

	temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty()
{
	return top == NULL;
}
int peek()
{

	if (!isEmpty())
		return top->data;
	else
		exit(1);
}


void tpop()//give trollies to customer
{
	struct trolies* temp;

  if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {

		temp = top;
		top = top->link;
		temp->link = NULL;

		// release memory of top node
		free(temp);

	}
		cout<<"Your Trolli No is :"<<top->data<<endl;
    	cout<<"                  ___"<<endl;
	    cout<<"                 /  |"<<endl;
	    cout<<"  ______________/   --"<<endl;
	    cout<<" |___/__ /___/_|     "<<endl;
	    cout<<" |__/___/___/__|     "<<endl;
	    cout<<" |_/___/___/___|     "<<endl;
	    cout<<"    _______/         "<<endl;
	    cout<<"     O   O           "<<endl;


}
//
void tdisplay()//display trollie number
{
	struct trolies* temp;


	if (top == NULL) {
		cout << "\nStack Underflow";
		exit(1);
	}
	else {
		temp = top;
		while (temp != NULL)
 {
	cout << temp->data << " ";
			temp = temp->link;
		}
	}
}

struct customer
{
string customername;

customer *link;
};

customer *front = NULL;
customer *rear = NULL;

//Function to check if queue is empty or not
bool isempty()
{
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}
void enqueue ( string name )//function to enter elements for customer name in queue
{
 customer *ptr = new customer();
 ptr->customername= name;
 ptr->link = NULL;

 //If inserting the first element/node
 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->link = ptr;
  rear = ptr;
 }
}

//function to delete/remove element customer name from queue
void dequeue ( )
{
 if( isempty() )
 cout<<"customer list is empty\n";
 else
 //only one element/node in queue.
 if( front == rear)
 {
  free(front);
  front = rear = NULL;
 }
 else
 {
  customer *ptr = front;
  front = front->link;
  free(ptr);
 }
}

//function to show the name at front for customer list
void showfront( )
{
 if( isempty())
 cout<<"the customer list is  empty\n";
 else
 cout<<"element at front is:"<<front->customername<<"\n";
}

//function to display queue
void displayQueue()
{
 if (isempty())
  cout<<"CUSTORMER LIST IS EMPTY\n";
 else
 {
  customer *ptr = front;
  while( ptr !=NULL)
  {
   cout<<"\t"<<ptr->customername<<"\t  "<<endl;
   ptr= ptr->link;

  }
 }
}


struct product
 {
	int ID;
	string proName;
	double prePrice;
	int quantity;
    struct    product* next;// using linked list
};

product *head=NULL;

////////////////////////////////////////////////////////////////////
 void addproduct()//add the product
{
	system("cls");
	int id,quant;           //  quant    for quantity
	string name;
	double pre;            //  pre for price
	struct product *t=new product;
	struct product *p=head;

	cout<<"\t\t\tEnter product ID:-";
	cin>>id;

	while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID ID\n";
        cout << "Please enter valid ID\n";
        cin >>id;
       }


	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID PRICE\n";
        cout << "Please enter valid price\n";
        cin >>pre;
       }

	t->prePrice=pre;
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID QUANTITY  \n";
        cout << "Please enter valid quantity\n";
        cin >>quant;
       }

	t->quantity=quant;
	if(head==NULL)
	{
	t->next=head;
	head=t;
	}
	else
	{
		while(p->next!=NULL)
    {
		p=p->next;
                        }
        p->next=t;
        t->next=NULL;

	}
	system("cls");
    cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";

	}

///////////////////////////////////////////////////////////////////////////////////////////
	int search(int id)                     //    for search item in list
 {
 	int count=1;
 	struct product *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }


////////////////////////////////////////////////////////////////////////
	void deleteProduct()
	{
		system("cls");
		display();
		int id;
		struct product *cur=head;
		struct product *pre=head;
		cout<<"\n\nEnter ID to delete that product:\n\n";
		cin>>id;
				while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID ID\n";
        cout << "Please enter valid id\n";
        cin >>id;
       }
		 if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
	int pos=0;
	int count=display();               //   for load no of nodes
	pos=search(id);                        //   for check weather desire node is exist or not
	if(pos<=count){

		while(cur->ID!=id){                //  for delete middle area products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"\n<<item is deleted>>\n";
	}else{
		cout<<"\n<<<Not found>>\n\n";
	}
	}

//////////////////////////////////////////////////////////////////////////////////
	void modify()//update existing product
	{
		int id;
		double price;        //    pre for price
		string productName;
		int newid; int newquantity;     //   pName for new name
		if (head == NULL)
    {
    	system("cls");
        cout<<"List is empty"<<endl;
    }
         else
	{
	    display();//display updated product
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		struct product *cur=head;
		int pos=0;
		int count=display();               //   for load no of nodes
	    pos=search(id);
	                            //   for check weather desire node is exist or not
	    if(pos<=count)
    {
		while(cur->ID!=id)
        {
			cur=cur->next;
		}
		cout<<"\nOld ID : "<<cur->ID<<endl;
		cout<<"\nOld Name : "<<cur->proName<<endl;
		cout<<"\nOld Price : "<<cur->prePrice<<endl;
		cout<<"\nOld Quantity : "<<cur->quantity<<endl;

		cout<<endl<<endl;
		cout<<"Enter new ID:";
		cin>>newid;
		while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID ID \n";
        cout << "Please enter valid id\n";
        cin >>newid;
       }

		cur->ID=newid;
		cout<<"Enter new Name:";
		cin>>productName;
		cur->proName=productName;
		cout<<"Enter new Price:";
		cin>>price;
		while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID PRICE \n";
        cout << "Please enter valid price\n";
        cin >>price;
       }

		cur->prePrice=price;
		cout<<"Enter new Quantity:";
		cin>>newquantity;
		while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID QUANTITY\n";
        cout << "Please enter valid quantity\n";
        cin >>newquantity;
       }

		cur->quantity=newquantity;
	}

	    else
    {
		cout<<id<<" is <<<Not found>>\n\n";
	}
	}
	}

//////////////////////////////////////////////////////////////////////////////////////

int display()//display existing product
{
		system("cls");
		int c=0;             //   c for count products
		struct product *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
		cout<<"=================================================================|\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t"<<p->prePrice<<"\t\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1;
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
		return c;
	    }
////////////////////////////////////////////////////////////////////////////////////////
	    string check(int quant)

	{              //        check function
	    int a = quant;
       stringstream ss;//convert integer datatype to string
       ss << a;
       string quantity = ss.str();

	    	if(quant<=0)
	    	return "out of stock!";
	    	else
	    	return quantity;
		}

///////////////////////////////////////////////////////////////////////
	void buy()
	{
        system("cls");
        display();
		string products[20];
		   //   for display sold items
		int pay=0,no,c=0,price,id,i=1;

        if(head==NULL)
        {
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
        }
	    else
        {
		cout<<"How many items you wanna to buy!\n";
		cin>>no;
		while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID NUMBER\n";
        cout << "Please enter valid number\n";
        cin >>no;
       }

        int count=display();           //   for store no of nodes  in c
		while (i<=no)
        {
			struct product *cur=head;
            int quant,cho;   a:           //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID ID\n";
        cout << "Please enter valid id \n";
        cin >>id;
       }

            if(id==-1){system("cls"); return;	}
	        pos=search(id);
	        if(pos<=count)
        {
	                        //     item is available in store
		 while(cur->ID!=id)
        {
			cur=cur->next;
		 }
           cout<<"How many quantities you want:";
	       cin>>quant;
	       while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID QUANTITY \n";
        cout << "Please enter valid quantity\n";
        cin >>quant;
       }

	       if(cur->quantity<quant)
           {
               cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
               cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
               goto a;

           }
           products[c]=cur->proName;   // this will conatin the items buy names in array;
		   c++;

	       pay=pay+(cur->prePrice*quant);         //     calculate Bill
	       cur->quantity=cur->quantity-quant;           //    change quantity
	       i++;

	     }
	    else
        {

		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

	    }
}
        string customer;
        cout<<"payment method\n";
        cout<<"press 1 to bank acount\n";
        cout<<"press 2 to pay cash\n";
        int p;
        cin>>p;
        	       while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID PAYMENT \n";
        cout << "Please enter valid payment method\n";
        cin >>p;
        	       }
        switch(p){
    case  1:
        cout<<"enter bank account\n";
        int account;
        cin>>account;
	       while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID ACCOUNT \n";
        cout << "Please enter valid account number\n";
        cin >>account;
	       }

        cout<<"\n\t\t Enter Your Name :"; cin>>customer;
        enqueue(customer);
	    system("cls");
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<",";
       }
        price=pay*(0.90);           //    with 10% discount
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";

        break;
    case 2:
        cout<<"Buying by cash\n";
        enqueue(customer);
	    system("cls");
	    cout<<"\n\t\t Enter Your Name :"; cin>>customer;
        enqueue(customer);
        cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0;i<no;i++)
      {              //    show that item you have bought
        cout<<products[i]<<",";
       }
        price=pay*(0.90);           //    with 10% discount
	    cout<<"\n\nOriginal price : "<<pay;
        cout<<"\n with 10% discount: "<<price<<"\nThank you! for the shopping\n\n";

        break;
       default :
        cout<<"there is no other payment method\n";

        }

          }
            }


 /////////////////////////////////////////////////////////////////////////////////////////
    void administator()
	{
		system("cls");
			int ch;


	do {

                 //            choice for below message



	cout<<"\t\t============================================"<<endl;
	cout<<"\t\t|          Administator Portal              |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 for ADD a new product    "<<endl;
	cout<<"\t\t     Enter 2 to display all products   "<<endl;
	cout<<"\t\t     Enter 3 for MODIFY Existing product"<<endl;
	cout<<"\t\t     Enter 4 for Delete a particular product item"<<endl;
	cout<<"\t\t     Enter 5 for Customers List "<<endl;
	cout<<"\t\t     Enter 6 for Dequeue customer"<<endl;
	cout<<"\t\t     Enter 0 for Main Menu"<<endl;


	cout<<"\nEnter Your choice >>>";   cin>>ch;


	while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID CHOICE \n";
        cout << "Please enter valid choice\n";
        cin >>ch;
       }






	switch(ch){
	case 1:
	addproduct();
	break;
case 2:
	system("cls");
    display();
    break;
case 3:
	modify();
	system("cls");
	break;
case 4:
	deleteProduct();
cout<<"\n-------Product is Deleted-------\n";
	break;
case 5:
	  system("cls");
      cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  displayQueue();
	   break;
case 6:
	   system("cls");
	  cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
	  dequeue();
      displayQueue();
	break;




default: system("cls");//clean screen

	}
}
while(ch!=0)	;
}



	                        //        Main function
int main()
{
      system("color a");//for consol color
                cout<<"\n\t\t\t*************************************************************************"<<endl;
	            cout<<"\n\t\t\t\t-----------JIMMA INSTITUTE OF TECHNOLOGY ----------- "<<endl;
                cout<<"\n\t\t\t\t--------FACLITY OF COMPUTING AND INFORMATICS-------- "<<endl;
	            cout<<"\n\t\t\t\t------------COMPUTER SCIENCE DEPARTMENT------------- "<<endl;
	            cout<<"\n\t\t\t\t------- DATA STRUCTURE AND ALGORITHM PROJECT-------- "<<endl;
	            cout<<"\n\t\t\t\t   Year(Semester):2(II)   Section: 1   Group: II     "<<endl;
	            cout<<"\n\t\t\t**************************************************************************\n"<<endl;
            	cout<<" \t\t\t\t..NAME.. \t\t\t\t\t\t ..ID..                                               "<<endl;
                cout<<"\t\t                                                                                     "<<endl;
            	cout<<"\t\t\t1. ABDULAHI FAJI ...............................................RU3100/11         "<<endl;
                cout<<"\t\t\t2. ADONAI DESALEGN........................................... . RU2280/13         "<<endl;
                cout<<"\t\t\t3. GATLAT BOTH..................................................RU2054/13         "<<endl;
                cout<<"\t\t\t4. GUTU YAEKOB..................................................RU2365/13         "<<endl;
                cout<<"\t\t\t5. SINTAYEHU DESALEGN...........................................RU1419/13         "<<endl;
                cout<<"\t\t\t6. YOHANNIS ABAY................................................RU3129/13         "<<endl;
                cout<<" \n\n\n\t\t\t\tTHANK YOU MR.SAMI FOR YOUR EFFORT TO TEACH US"<<endl;
            	cout<<"\t\t\t\t*********************************************"<<endl;
     system("pause"); //to stop with out pressing any key
     system("cls");
  for(int i=0;i<=50;i++)
     {

 	push(i);//used for push Trolli to customer
	 }

    int ch;
	while(ch!=3){

	                     //            choice for below message

    cout<<"\n\t\t|--------<Main Menu>-----------|";
      cout<<"\n\n";
	cout<<"\t\t 1)Administator of Market\n";
	cout<<"\t\t 2)Customer               \n";
	cout<<"\t\t 3)Exit                    \n";



	cout<<"\nEnter Your choice >>>";cin>>ch;
	while (cin.fail()){
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input
        cout << "INVALID CHOICE \n";
        cout << "Please enter valid choice\n";
        cin >>ch;
       }

	switch(ch){
	case 1:


		administator();
		break;

	case 2:
		cout<<endl<<endl;
		tpop();
		system("pause");
	    buy();
	    break;

    case 3:
    	cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	break;
    default:
        system("cls");
        cout<<"\n\nSORRY YOU HAVE ENTERED WRONG CHOICE PLEASE ENTER CORRECT CHOICE\n\n"<<endl;

	}
}
return 0;	}






