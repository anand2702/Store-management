#include<memory>
#include<exception>
#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>

using namespace std;
class stock;

int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;

        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid+1, r, x);
   }

   // We reach here when element is not
   // present in array
   return -1;
}
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
   l  --> Starting index,
   h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;

    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition( arr, l, h );

        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}
class details{
friend class customer;
int arr[1000];
};
class customer
{
    private:
        int customer_id;
        char customer_name[50];
        char customer_email[30];
        char customer_mobile[15];
    public:

    void ins(){
        ofstream file;
        details dobj;
        int i=0;
        file.open("customer.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of customer:\n";
        cin>>customer_id>>customer_name>>customer_mobile>>customer_email;
        dobj.arr[i]=customer_id;
        i++;
        file<<customer_id<<" "<<customer_name<<" "<<customer_mobile<<" "<<customer_email<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
    }

    void show()
    {
        ifstream file1;
        file1.open("customer.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>customer_id>>customer_name>>customer_mobile>>customer_email;
            while(!file1.eof()){
            cout<<customer_id<<" "<<customer_name<<" "<<customer_mobile<<" "<<customer_email<<endl;
            file1>>customer_id>>customer_name>>customer_mobile>>customer_email;
            }
        }
    }
friend class details;
};

class product
{
    public:
        int product_id;
        int product_number;
        char product_type[20];
        char product_description[50];
        int product_price;

        void ins(){
        ofstream file;
        file.open("product.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of product:\n";
        cin>>product_id>>product_number>>product_type>>product_description>>product_price;
        file<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
        }
        void show()
    {
        ifstream file1;
        file1.open("product.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{

            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            while(!file1.eof()){
            cout<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<endl;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            }
        }
    }
    int search(int n)
    {
    ifstream file1;
        file1.open("product.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{ int f=0;
            cout<<"File opened and the contents in the file are:\n";
            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            while(!file1.eof()){
            if(product_id==n)
            f=1;
            if(f==1){
                return product_price;}
            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            }
        }
        cout<<"No such product found"<<endl;
        return 0;
    }
    void delet(int n)
    {
    fstream file1,file2;

        file1.open("product.dat",ios::in);
    file2.open("product1.dat",ios::out);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
if( !file2)
    cout<<"Error"<<endl;
{


            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            while(!file1.eof()){
            if(product_id!=n)
            {
            file2<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<endl;

            }
            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            }
        }
        file1.close();
        file2.close();
        remove("product.dat");
        rename("product1.dat","product.dat");

}    }
    void modify(int n)
    {
    fstream file1,file2;

        file1.open("product.dat",ios::in);
    file2.open("product1.dat",ios::out);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
if( !file2)
    cout<<"Error"<<endl;
    else{
int pr;


            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            while(!file1.eof()){
            if(product_id==n)
            {
                cout<<"Enter new price"<<endl;

                cin>>pr;
                product_price=pr;
            }

            file2<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<endl;


            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            }
        }
        file1.close();
        file2.close();
        remove("product.dat");
        rename("product1.dat","product.dat");

}}
};
class payment
{
    private:
    int payment_id;
    int payment_customer_id;
    int payment_amount;
    char payment_date[15];
    char payment_description[20];
    public:
        void ins(){
        ofstream file;
        file.open("payment.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of payment:\n";
        cin>>payment_id>>payment_customer_id>>payment_amount>>payment_date>>payment_description;
        file<<payment_id<<" "<<payment_customer_id<<" "<<payment_amount<<" "<<payment_date<<" "<<payment_description<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
        }
        void show()
    {
        ifstream file1;
        file1.open("payment.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>payment_id>>payment_customer_id>>payment_amount>>payment_date>>payment_description;
            while(!file1.eof()){
            cout<<payment_id<<" "<<payment_customer_id<<" "<<payment_amount<<" "<<payment_date<<" "<<payment_description<<endl;
            file1>>payment_id>>payment_customer_id>>payment_amount>>payment_date>>payment_description;
            }
        }
    }

};
class role
{
    private:
    int role_id;
    char role_title[20];
    char role_description[20];
    public:
        void ins(){
        ofstream file;
        file.open("role.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of customer:\n";
        cin>>role_id>>role_title>>role_description;
        file<<role_id<<" "<<role_title<<" "<<role_description<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
    }

    void show()
    {
        ifstream file1;
        file1.open("role.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>role_id>>role_title>>role_description;
            while(!file1.eof()){
            cout<<role_id<<" "<<role_title<<" "<<role_description<<endl;
            file1>>role_id>>role_title>>role_description;
            }
        }
    }
};
class permission
{
    private:
    int permission_id;
    int permission_role_id;
    char permission_title[20];
    char permission_module[20];
    char permission_description[20];
    public:
        void ins(){
        ofstream file;
        file.open("permission.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of payment:\n";
        cin>>permission_id>>permission_role_id>>permission_title>>permission_module>>permission_description;
        file<<permission_id<<" "<<permission_role_id<<" "<<permission_title<<" "<<permission_module<<" "<<permission_description<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
        }
         void show()
    {
        ifstream file1;
        file1.open("permission.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>permission_id>>permission_role_id>>permission_title>>permission_module>>permission_description;
            while(!file1.eof()){
            cout<<permission_id<<" "<<permission_role_id<<" "<<permission_title<<" "<<permission_module<<" "<<permission_description<<endl;
            file1>>permission_id>>permission_role_id>>permission_title>>permission_module>>permission_description;
            }
        }
    }
};
class sales
{
private:
    int sales_id;
    char sales_type[15];
    char sales_description[20];
    int sales_amount;
    int sales_customer_id;
public:
    void ins(){
        ofstream file;
        file.open("sales.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of payment:\n";
        cin>>sales_id>>sales_type>>sales_description>>sales_amount>>sales_customer_id;
        file<<sales_id<<" "<<sales_type<<" "<<sales_description<<" "<<sales_amount<<" "<<sales_customer_id<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
        }
        void show()
    {
        ifstream file1;
        file1.open("sales.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>sales_id>>sales_type>>sales_description>>sales_amount>>sales_customer_id;
            while(!file1.eof()){
            cout<<sales_id<<" "<<sales_type<<" "<<sales_description<<" "<<sales_amount<<" "<<sales_customer_id<<endl;
            file1>>sales_id>>sales_type>>sales_description>>sales_amount>>sales_customer_id;
            }
        }
    }
};
class store
{
private:
    int store_id;
    char store_name[20];
    char store_description[30];
    char store_type[20];
public:
    void ins(){
        ofstream file;
        file.open("store.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of customer:\n";
        cin>>store_id>>store_name>>store_description>>store_type;
        file<<store_id<<" "<<store_name<<" "<<store_description<<" "<<store_type<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
    }

    void show()
    {
        ifstream file1;
        file1.open("store.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>store_id>>store_name>>store_description>>store_type;
            while(!file1.eof()){
            cout<<store_id<<" "<<store_name<<" "<<store_description<<" "<<store_type<<endl;
            file1>>store_id>>store_name>>store_description>>store_type;
            }
        }
    }


    void search(int n)
{
    ifstream file1;
    int arr[1000],i=0;
        file1.open("store.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
                file1>>store_id>>store_name>>store_description>>store_type;
            while(!file1.eof()){
                arr[i]=store_id;
                i++;
                file1>>store_id>>store_name>>store_description>>store_type;
        }
        quickSortIterative(arr,0,i);
        binarySearch(arr,0,i,n);

}}
};
class user
{
private:
    int user_id;
    int user_role_id;
    char user_name[20];
    char user_email[30];
    char user_dob[15];
    char user_pass[40];
public:
    void ins(){
        ofstream file;
        file.open("user.dat",ios::app);
        if(!file)
        {
            cout<<"Error in creating file.."<<endl;
            }
        cout<<"File created successfully."<<endl;
        file.seekp(0,ios::end);
        cout<<"enter details of user:\n";
        cin>>user_id>>user_role_id>>user_name>>user_email>>user_dob>>user_pass;
        file<<user_id<<" "<<user_role_id<<" "<<user_name<<" "<<user_email<<" "<<user_dob<<" "<<user_pass<<endl;
        file.close();
        cout<<"File saved and closed succesfully."<<endl;
        }
        void show()
    {
        ifstream file1;
        file1.open("user.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
            cout<<"File opened and the contents in the file are:\n";
            file1>>user_id>>user_role_id>>user_name>>user_email>>user_dob>>user_pass;
            while(!file1.eof()){
            cout<<user_id<<" "<<user_role_id<<" "<<user_name<<" "<<user_email<<" "<<user_dob<<endl;
            file1>>user_id>>user_role_id>>user_name>>user_email>>user_dob>>user_pass;
            }
        }
    }
    int validate()
    {int id;

                int f=0;
                int uid;char upass[40];
    char pass[40];
    cout<<"Enter you user id"<<endl;
        cin>>id;
        cout<<"enter your password"<<endl;
        cin>>pass;
            ifstream file1;
        file1.open("user.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
                int f=0;
                int uid;char upass[100];

            file1>>user_id>>user_role_id>>user_name>>user_email>>user_dob>>user_pass;
            while(!file1.eof()){
                uid=user_id;
            strcpy(upass,user_pass);
            if(uid==id && strcmp(upass,pass)==0)
              {



                    return 1;
     }       file1>>user_id>>user_role_id>>user_name>>user_email>>user_dob>>user_pass;
            }
            return 0;
        }
      }

};
class stock:public product
{   public:
    int product_qty;
    void dec(int n)
    {
fstream file1,file2;
        file1.open("productst.dat",ios::in);
        file2.open("productst1.dat",ios::app);

        if(!file1){
        cout<<"Error in opening file stock";
        }
        else{
                int f=0;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty;
            while(!file1.eof()){
            f=0;
            if(product_id==n)
                    f=1;
            if(f==1)
                product_qty--;
            file2<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<" "<<product_qty<<endl;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty;
            }
        }
        file1.close();
        file2.close();
        remove("productst.dat");
        rename("productst1.dat","productst.dat");


    }

    void show()
    {
ifstream file1;
        file1.open("productst.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{ int f=0;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty;
            while(!file1.eof()){
            cout<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<" "<<product_qty<<endl;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty;
            }
        }
    }
};
class management:public stock              //for management work;
{
    public:
int a[1000],c[1000],d[1000];               //for quantiy on price;

int b[1000],count1=0,count=0;  //for most sold;

management()
{
        ifstream file1;                                  //opening file
        file1.open("productst.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{
                product pobj;
         //   cout<<"File opened and the contents in the file are:\n";
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty; //reading from file;
            while(!file1.eof())
			{
			a[count]=product_price;                                        //putting values
			count++;
			b[count1]=product_qty;
			count1++;

            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty;

			}

}

}
void max_heapify(int *a, int i, int count)              //heap used
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= count)
    {
        if (j < count && a[j+1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void build_maxheap()
{
    int i;
    for(i = count/2; i >= 1; i--)
    {
        this->max_heapify(a,i,count);
    }
}
void showsorted()
{int i;
quickSortIterative (a,0,count);
for(i=0;i<count;i++){
cout<<a[i]<<endl;
}
}
void mostsold()
{
quickSortIterative (b,0,count1);
}
void showagain()
{
int i;
for(i=count1-1;i>-1;i--){
cout<<b[i]<<endl;
}
}
   void showprod(int n)
{
 ifstream file1;
        file1.open("product.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{ int f=0;
           // cout<<"File opened and the contents in the file are:\n";

            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            while(!file1.eof()){
                    f=0;
            if(product_id==n)
                f=1;
            if(f==1){
                    cout<<product_id<<" "<<product_number<<" "<<product_type<<" "<<product_description<<" "<<product_price<<endl;
                return ;}
            file1>>product_id>>product_number>>product_type>>product_description>>product_price;
            }
        }
}
void showfrequency()
{ ifstream file1;                                  //opening file
        file1.open("productst.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{  int j=0;
                product pobj;
            //cout<<"File opened and the contents in the file are:\n";
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty; //reading from file;
            while(!file1.eof())
            {c[j]=product_qty;
            j++;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty; //reading from file;


            }
            file1.close();
            for(int i=0;i<count1;i++)
            {
            d[i]=b[i]-c[i];
            }
            ifstream file1;                                  //opening file
        file1.open("productst.dat",ios::in);
        if(!file1){
        cout<<"Error in opening file.";
        }
        else{  int j=0;
                product pobj;
        file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty; //reading from file;
            while(!file1.eof())
            { cout<<product_id<<" "<<d[j]<<" "<<endl;
                          j++;
            file1>>product_id>>product_number>>product_type>>product_description>>product_price>>product_qty; //reading from file;


            }

}}}

};
int main()
{
    customer c1;
    char ch='y';
    int c,v;
    user uobj;
    v=uobj.validate();
    if(v==1){
    uobj.show();
    cout<<"Press 1 to enter management \nPress 2 to enter billing"<<endl;
    cin>>c;
    if(c==2)
    { int s=0;

        product pobj;
        customer cobj;
        cobj.ins();
    int n;
    stock st;

        while(ch=='y')
        {   int n,p;
cout<<"Enter product id";
cin>>n;
            p=pobj.search(n);
            s=s+p;
            st.dec(n);
            cout<<"Do you want to continue?(y/n)"<<endl;
            cin>>ch;
        }
        payment pay;
        cout<<"Total amount is:"<<s<<endl;
        pay.ins();
    }
    else
    {   cout<<"Enter your id and password"<<endl;
    int id,pass;
    int choice;
    cin>>id>>pass;
    if(id==123 && pass==123456){
            while(ch=='y'){
        cout<<"Welcome to management"<<endl;
        cout<<"Press 1 to see list stock"<<endl;
        cout<<"Press 2 to modify price any item\n";
        cout<<"Press 3 to delete any item\n";
        cout<<"Press 4 to add new user\n";
        cout<<"Press 5 to list all users\n";
        cout<<"Press 6 to list all stores"<<endl;
        cout<<"Press 7 to search any specific stoe by store id"<<endl;
        cout<<"Press 8 to list all customers"<<endl;
        cout<<"Press 9 to see products in sorted amount"<<endl;
        cout<<"press 10 to see product quantity in sorted order"<<endl;
        cout<<"Press 11 to see products in sorted order of most bought"<<endl;
        cin>>choice;
        store sobj;
        user u;
        product p;
        customer cobj;
        stock s;
        management m;
        switch(choice)
        {
            case 7:
            cout<<"Enter store id";
            int n;
            cin>>n;
            sobj.search(n);
            break;
            case 6:
            sobj.show();
            break;
            case 5:
            u.show();
            break;
            case 4:
            u.ins();
            break;
            case 3:
                cout<<"Enter product id to be deleted"<<endl;
                cin>>n;
                p.delet(n);
                break;
            case 2:
                cout<<"Enter product id to be modified"<<endl;
                cin>>n;

                p.modify(n);
                break;
             case 8: cobj.show();
             break;
             case 1: s.show();
             break;
             case 10:
                m.showagain();
                break;
             case 9:
                m.showsorted();
                break;
             case 11: m.showfrequency();
             break;
             default: cout<<"Wrong choice enterd"<<endl;

        }
        cout<<"Do you want to continue?(y/n)"<<endl;
        cin>>ch;
    }}
    else
        cout<<"You dont have this access"<<endl;
    }}
    else
        cout<<"Wrong id or pass"<<endl;
    return 0;
}
