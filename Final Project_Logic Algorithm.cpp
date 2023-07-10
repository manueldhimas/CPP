#include <iostream>
#include <iomanip>

using namespace std;

void line()
{
cout<<"----------------------------------------------------------------------\n";
}

int main()
{
int et,n,r[5],en[10],salary=3800000,ot,otp[5],wh=240,otb=50000,ns[5],t=0;
char enm[20][20],p;
float pa[5],tax[5];

start:

cout<<"Employee salary calculation\n\n";
cout<<"Number of employee : ";cin>>et;

for (n=1;n<=et;n++)
{
    cout<<"Employee Number "<<n<<endl;
    cout<<"Employee Name : ";cin>>enm[n];
    cout<<"Rank (1/2/3) : ";cin>>r[n];
    cout<<"Total of Working Hour : ";cin>>en[n];
}

cout<<"                             PIJAR FOUNDATION\n";

line();
cout<<"No  Employee         Positional    Overtime    Tax         Nett  \n";
cout<<"    Name             Allowance     Pay                     Salary\n";

line();
for (n=1;n<=et;n++)
{
cout<<setiosflags(ios::left)<<setw(4)<<n;
cout<<setiosflags(ios::left)<<setw(17)<<enm[n];

if (r[n]==1)
{
    pa[n]=salary*0.05;
}else if (r[n]==2)
{
    pa[n]=salary*0.1;
}else if (r[n]==3)
{
    pa[n]=salary*0.15;
}else
{
    pa[n]=0;
}

cout<<setiosflags(ios::left)<<setw(14)<<pa[n];

if (en[n]>240)
{
    ot=en[n]-wh;
    otp[n]=ot*otb;
}else
{
    otp[n]=0;
}

cout<<setiosflags(ios::left)<<setw(12)<<otp[n];
tax[n]=(salary+pa[n]+otp[n])*0.1;
cout<<setiosflags(ios::left)<<setw(12)<<tax[n];
ns[n]=salary+pa[n]+otp[n]-tax[n];
cout<<setiosflags(ios::left)<<setw(12)<<ns[n]<<endl;
t=t+ns[n];
}

line();

cout<<"                                                    Total "<<t;
Try:
cout<<"\nInput Again Y/N : ";cin>>p;
if (p=='Y'||p=='y')
{
    goto start;
}else if (p=='n'||p=='N')
{
    cout<<"\nThank you for using this program :D";
}else
{
    cout<<"Error, Try again!!\n ";
    goto Try;
}

}

