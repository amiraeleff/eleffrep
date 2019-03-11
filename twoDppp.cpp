#include<iostream>
#include<conio.h>
//#include<math.h>
//# define pi 3.14159;
#include<math.h>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////
 long long int factorial(int n)
{  

     if(n==1)
		 return 1;
	 else 
		 return n*factorial(n-1);
	 
}
/////////////////////////////////////////////////////////////////////////////////////
double distanceCalculate(double x1, double y1, double x2, double y2)
{
	double x = x1 - x2; //calculating number to square in next step
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);                  

	return dist;
}
///////////////////////////////////////////////////////////////////////////////////
double getmin(double* arr, int n)
{
	double minval=*(arr+0);
	for( int i=1; i<n;i++)
	{
		if(minval>*(arr+i))
			minval=*(arr+i);

	}
	return minval;
}
///////////////////////////////////////////////////////////////////////////////////////////////

double calculate(double base, int n)
{
	 double result=1.0;
	for(int i=n;i>=1;i--)
	{
		result*=(double)base/(double)i;
	
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int SquareLength= 10;
	int Area=SquareLength*SquareLength;
	double Lambda;
	double min;
	double CummMin;
	double Distance;
	double XPoints[200] ; // xpoints
	double YPoints[200];  // ypoints
	double CummAvgDistanceOfOnePoint;
	double PropOfOneN;
	double Allavg;
	double SimulationOfLambda;
	double Npts;
	double base;
	double fact;
	float Rand;
	for( Lambda= 0.1 ; Lambda<1 ; Lambda+=0.1)
	{
		Npts=2*Lambda*Area;
		base=Lambda*Area;
		SimulationOfLambda=0;
      for (int n=2; n<=Npts; n++)

   { 
	   PropOfOneN=0;
	  // calculate factorial part of poisson
	   
	   fact= calculate(base,n);
	 PropOfOneN=exp(-Lambda * Area)*fact; //poisson propability  for each n 

	 CummAvgDistanceOfOnePoint=0;

	for(int k=0 ;k<1000;k++) // realizations
{    
	CummMin=0; // sum of all minimum of realization
	
	 for (int i=0; i<n;i++ )  // Generate n random numbers for X and y
	 {
		 Rand =rand();
		 XPoints[i]= Rand/3276.8*SquareLength/10;
		 Rand=rand();
		YPoints[i]= Rand/ 3276.8* SquareLength/ 10;
		//cout<<x[i]<<"\t"<<y[i]<<"\n";
	 }

	
	for(int i=0;i<n;i++)
	
	{   // int l=0;
	      min=1000;
		for(int j=0;j<n;j++)
		{  //dist=0;
			if(j!=i)
			{ 
				 double X= XPoints[i]-XPoints[j];   // calculate distance between each two points
				 double Y= YPoints[i]-YPoints[j];
				 Distance = sqrt(X*X + Y*Y);
				 if(Distance<min)
					 min=Distance;
						
			}
			
		} // end of j
		
		//cout<<"minmum  "<< min<<"\n";
		
		CummMin+=min; // get cummulative minimum of one point

		//cout<<"minimum is mm"<<mm<<"\n";

	}// end of i
	
	//cout<<"greate min" << great_min;
	   double AverageDistanceOneRealization= CummMin/n;
	  //cout<<"avrage min/n"<<mm<<"\n";
	   CummAvgDistanceOfOnePoint+=AverageDistanceOneRealization; // get avarage of one realization;

}//end of realization
	//cout<<"avarage distance avg+=m"<<avgdist;
     
	  Allavg= CummAvgDistanceOfOnePoint/1000;  // average of all realizations    

	 //cout<<"avarage dist= "<<Allavg <<"\t"<<"prop"<<pr_m;
	  double AverageMultplication= Allavg*PropOfOneN;    // multiplying each prop with it's all_average
	 //cout<<"avg* prop " << avgmult;

	   SimulationOfLambda+= AverageMultplication  ;  // sum all multpilcations
	}// end of n


 cout<<"\n \n lambda="<<Lambda<<"\tsimulation d = " <<SimulationOfLambda;
	double theortical = 1/sqrt((Lambda*3.14));

	cout<<"\t Theortical =   "<< theortical;
	cout<<"\t Diff% =" << 100*(theortical-SimulationOfLambda)/theortical;
	}
     getch();
	}