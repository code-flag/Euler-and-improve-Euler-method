#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <windows.h>
using namespace std;

double a=0,b=0;
int except=0; double initial_v=0;
int index=0; // variable to activate index loop var or deactivate it
int i_sp=0;  // to activate second part
int sp=0;
static int row_num=5;
double fp_result=1, sp_result=0;
double fp_iv_result=1, sp_iv_result=1;
double fp_iv_result2=0, sp_iv_result2=0;
double final_result=0;
double x_i_result=0, y_i_result=0, e_result=0;
double h;
char ope_plus=0, ope_minus=0;
char op, i_op;

			int i_n = 0, i_m=0;
			double const_v = 0, const_iv = 0;
			double e= 2.71828185;
            double y_last, y_next;
            char v[15]={0};
            string val;
void strtofloat(string s);
void get_equation();
void prog();
void setTableRow();
void about();
void _help();
double f_x_y(double x, double y);
void option();
void euler_m(double x, double y, int k);
void imp_euler_m(double x, double y, int k);
//void display(string s, double x[k], double y[k],double z[k], int k);

int main()
{
    option();
    cout<<endl;
     cout<<endl;

}


void setTableRow()
{
    system("cls");
    system("color 3f");
    cout<<"\n\t\t\t============ SETTINGS ==========\n\n";
    cout<<"\nEnter the number of iteration you want to perform for the equations : ";
    cin>>row_num;
    if(isalpha(row_num))
    {
        cout<<"\n\t\t\tInvalid entry. Please try again \n";
        system("pause");
        option();

    }
    else{
        cout<<"\n\t\t\tNumber of Iteration is successfully set to "<<row_num<<"\n";
        system("pause");
         option();
    }
    cin.ignore();
}

void get_equation()
{
    cin.ignore();
    string s;
    int i=0;
	cout<<"\n\n\t\tGreat Computational Mathematics\n\n";

    cout<<"\n\tWrite your equation below. \n\tNote: do not add y= or dy/dy= just write starting after =, ";
    cout<<"\n\talso to raise a variable to any power index always add this '^(...) \n\te.g e^(2x) or x^(1+y) and ";
    cout<<"dont forget to end the equation with ; \n";
    cout<<"\n-----------------------------------------------------------------------------\n";
	//cin.getline(v,'\n');
		    do
                {
                    cout<<"\n\t\t\t Type here end with ';' : ";
                       getline(cin,val,'\n');
                       if(val[val.length()-1] != ';')
                       {
                           cout<<"\n\t\t\tInvalid Entry \n";
                       }
                }while(val[val.length()-1] != ';');
        do
        {
             except =0;
            cout<<"\n\tenter initial value for y : ";
            cin>>s;
            strtofloat(s);
        }while(except == 1);
		b = initial_v;

		 do
        {
             except =0;
            cout<<"\n\tenter initial value for x : ";
            cin>>s;
            strtofloat(s);
        }while(except == 1);
		a = initial_v;

        do
        {
            except =0;
            cout<<"\n\tenter the step size h : ";
            cin>>s;
            cin.ignore();
            strtofloat(s);
        }while(except == 1);
		h = initial_v;

        for(int j = 0; j< val.length(); j++){
            v[j]=val[j];
        }
        //cout<<v;
}

/****************************************************************************************
    This function extract variables in the equation as well as the operators and calculate
    them accordingly.
    ************************************************************************************/

double f_x_y(double x, double y)
{
    int i=0, n=0;

	int m=0;
        try{
                do          //while the v[i] as not gotten to the end of the vale stored
		{
			while(v[i] != '+' && v[i] != '-' && v[i] != ';' && sp != 1) //first part of the equation while the equation as not gotten to operator
			{
				if(isdigit(v[i]) && i_n != 1)             // this loop gets all the number before letter
				{

					if (n < 1)                      //
					{
						const_v =  v[i] - 48;  /* code */
					}
					else
					{
						const_v =  (const_v * 10) + (v[i] - 48) ;
					}
					n++;
					fp_result = const_v;
					// cout<<"constant loop"<<n<<" val : "<<const_v<<"\n";
				}
				else if (!isdigit(v[i]) && v[i+1] != '^' && index !=1)            // if the next value is a letter and it doesnt raise to power index
				{
				    i_n != 1;

					if (v[i] == 'x')                                // if its x save as 100
					{
						fp_result = fp_result  * x;
					//	cout<<"variable x loop1\n";
					}

					if (v[i] == 'y')
					{
						fp_result = fp_result  * y;
						//cout<<"variable y loop1\n";
					}
                                if (v[i] == 'e')
								{
									throw 2;
								}
								if (v[i] == '(' && v[i-1] != '^')
								{
									throw 3;
								}
				}
				else if (!isdigit(v[i]) && v[i+1] == '^')               // if the next value is a letter and it raise to power index
				{
					i_n = 1;
                    index =1;

					if (v[i] == 'x')
					{
						m++;
						i= i+2;
						//cout<<"\nfp variable x with index\n";
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i]-48) ;
								}
                                fp_iv_result = const_iv ;
								i_n++;
						//		cout<<"\nx_i constant loop1 "<<const_iv<<"\n";
							}

							else if (!isdigit(v[i]) && v[i+1] != '^')
							{
								i_m++;

								if (v[i] == 'x')
								{
									fp_iv_result = fp_iv_result * x;
								//	cout<<"\nx_i variable x loop1\n";
								}

								if (v[i] == 'y')
								{
									fp_iv_result = fp_iv_result * y;
								//	cout<<"\nx_i variable y loop1\n";
								}


								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^')
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}

						i++;
						}


							if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2=1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2=1;
							}

							while(v[i] != ')' && i_sp == 1)  // second part of the index variable
							{
									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv * 10) + (v[i]-48) ;

										}
                                        fp_iv_result2 = const_iv;
										i_n++;
								//		cout<<"\nx_i constant loop2 "<<const_iv<<"\n";
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{
                                        i_m++;

										if (v[i] == 'x')
										{
											fp_iv_result2 = fp_iv_result2 * x;
									//		cout<<"\nx_i variable x loop2\n";
										}

										if (v[i] == 'y')
										{
											fp_iv_result2 = fp_iv_result2 * y;
										//	cout<<"\nx_i variable 2 loop2\n";
										}

									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}
									}
							i++;
							}
							 i_sp=0; // reset variable
							 if(i_op == '+')
                             {
                                  x_i_result = fp_iv_result  + fp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  x_i_result = fp_iv_result -  fp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  x_i_result = fp_iv_result;
                             }
                             fp_result = fp_result * pow(x , x_i_result);

							 fp_iv_result =1; fp_iv_result2 = 0;
					} // end of x index variable

				else if (v[i] == 'y')    // while the variable y have an index variable
					{
					  //  cout<<"\nfp variable y with index";
						m++;
						i_n =1; i_m =0;
						i= i+2;
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i] - 48) ;

								}
								fp_iv_result = const_iv;
							//	cout<<"\ny_i constant loop1 "<<const_iv<<"\n";
								i_n++;
							}

							else if (!isdigit(v[i]) && v[i+1] != '^')
							{
								i_m++;
								if (v[i] == 'x')
								{
									fp_iv_result = fp_iv_result * x;
							//		cout<<"\ny_i variable x loop1\n";
								}

								if (v[i] == 'y')
								{
									fp_iv_result = fp_iv_result * y;
								//	cout<<"\ny_i variable y loop1\n";
								}

								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^' )
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}
							i++;
						}


							if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2 = 1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2 =1;
							}

							while(v[i] != ')'  &&  i_sp ==1 )
							{
									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv * 10) + (v[i]-48) ;

                                                if(i_op == '+')
                                                 {
                                                      y_i_result = fp_iv_result  + fp_iv_result2;
                                                 }
                                                  if(i_op == '-')
                                                 {
                                                      y = fp_iv_result -  fp_iv_result2;
                                                 }
                                                 if(i_op != '+' && i_op != '-')
                                                 {
                                                      y_i_result = fp_iv_result;
                                                 }
                                                 fp_result = fp_result * pow(y , y_i_result);

                                                 fp_iv_result =1; fp_iv_result2 = 0;

										}

                                        fp_iv_result2 = const_iv;

										//cout<<"\ny_i constant loop2 "<<const_iv<<"\n";
										i_n++;
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{

										i_m++;

										if (v[i] == 'x')
										{
											fp_iv_result2 = fp_iv_result2 * x;
											//cout<<"\ny_i variable x loop2\n";
										}

										if (v[i] == 'y')
										{
											fp_iv_result2 = fp_iv_result2 * y;
											//cout<<"\ny_i variable y loop2\n";
										}

										 /* code */
									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}

										 /* code */
									}

									i++;

							}

                    i_sp=0;

                     if(i_op == '+')
                             {
                                  y_i_result = fp_iv_result  + fp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  y = fp_iv_result -  fp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  y_i_result = fp_iv_result;
                             }
                             fp_result = fp_result * pow(y , y_i_result);

							 fp_iv_result =1; fp_iv_result2 = 0;
					}

					// for exponential e

					else if (v[i] == 'e')
					{
					    //cout<<"\n Exp loop ";
						m++;
						i_m = 0;
						i_n =1;
						i= i+2;
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i] - 48) ;

								}
								fp_iv_result = const_iv;
								//cout<<"\nExp constant loop1 "<<const_iv<<"\n";
								i_n++;
							}

							else if (!isdigit(v[i]) && v[i+1] != '^' )
							{
								if (v[i] == 'x')
								{
									fp_iv_result = fp_iv_result * x;
									//cout<<"\n Exp variable x loop1 ";
								}

								if (v[i] == 'y')
								{
									fp_iv_result = fp_iv_result * y;
									//cout<<"\n Exp variable y loop1 ";
								}
								i_m++;
								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^')
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}
							i++;
						}

						if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2 = 1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								fp_iv_result2 = 1;
							}

							while(v[i] != ')')
							{

									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv *10) + (v[i] -48) ;
										}
										fp_iv_result2 = const_iv;
										i_n++;
										//cout<<"\nExp constant loop2 "<<const_iv<<"\n";
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{
										if (v[i] == 'x')
										{
											fp_iv_result2= fp_iv_result2 * x;
											//cout<<"\n Exp variable x loop2 ";
										}

										if (v[i] == 'y')
										{
											fp_iv_result2= fp_iv_result2 * y;
											//cout<<"\n Exp variable y loop2 ";
										}
										i_m++;
										 /* code */
									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}
									}
									i++;
							}

                         if(i_op == '+')
                             {
                                  e_result = fp_iv_result  + fp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  e_result = fp_iv_result -  fp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  e_result = fp_iv_result;
                             }
                             fp_result = fp_result * pow(e, e_result);

							 fp_iv_result =1; fp_iv_result2 = 0;
					}

                index =0;  // reset variable
				} // end of index loop
				else{

				}
			i++;
			}

			/********************************************************************************************************
			*********************************************************************************************************
			 second part of the equation after operator
			 *******************************************************************************************************
			 *******************************************************************************************************/
			m=0; n=0;
			if (v[i] == '+')
			{
                sp=1;
				ope_plus++;
				op = '+';
				i_op ='0';
				/* code */

				i++;
				sp_result=1;
			}
			if (v[i] == '-')
			{
                sp=1;
				ope_minus++;
				op = '-';
				i_op ='0';
				i++;
				sp_result=1;
			}

			while(v[i] != ';' && sp == 1 ) //while the equation is at the second part;
			{
				if(isdigit(v[i]) && i_n != 1)             // this loop gets all the number before letter
				{

					if (n < 1)                      //
					{
						const_v =  v[i] - 48;  /* code */
					}
					else
					{
						const_v =  (const_v * 10) + (v[i] - 48) ;

					}
					n++;
					//cout<<"SP constant loop"<<n<<"SP  val : "<<const_v<<"\n";

					sp_result = const_v;
				}
				else if (!isdigit(v[i]) && v[i+1] != '^' && index !=1)            // if the next value is a letter and it doesnt raise to power index
				{
				    i_n != 1;
					if (v[i] == 'x')                                // if its x save as 100
					{
						m++;

						sp_result = sp_result * x;
						//cout<<"SP variable x loop1\n";
					}

					if (v[i] == 'y')
					{
						m++;

						sp_result = sp_result * y;
						//cout<<"SP variable y loop1\n";
					}
					if (v[i] == 'e')
								{
									throw 21;
								}
								if (v[i] == '(' && v[i] != '^')
								{
									throw 22;
								}

				}
				else if (!isdigit(v[i]) && v[i+1] == '^')               // if the next value is a letter and it raise to power index
				{
					i_n = 1;
                    index =1;

					if (v[i] == 'x')
					{
						m++;

						i= i+2;
						//cout<<"\nSP variable x with index\n";
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i]-48) ;
								}

								sp_iv_result = const_iv;
								i_n++;
								//cout<<"\nSP x_i constant loop1 "<<const_iv<<"\n";
							}

							else if (!isdigit(v[i]) && v[i+1] != '^')
							{
								i_m++;

								if (v[i] == 'x')
								{
									sp_iv_result = sp_iv_result * x;
									//cout<<"\nSP x_i variable x loop1\n";
								}

								if (v[i] == 'y')
								{
									sp_iv_result = sp_iv_result * y;
									//cout<<"\nSP x_i variable y loop1\n";
								}

								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^')
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}

						i++;
						}


							if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2=1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2=1;
							}

							while(v[i] != ')' && i_sp == 1)  // second part of the index variable
							{
									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv * 10) + (v[i]-48) ;

										}
										i_n++;
										sp_iv_result2 = const_iv;
										//cout<<"\nSP x_i constant loop2 "<<const_iv<<"\n";
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{
                                        i_m++;

										if (v[i] == 'x')
										{
											sp_iv_result2 = sp_iv_result2 * x;
											//cout<<"\nSP x_i variable x loop2\n";
										}

										if (v[i] == 'y')
										{
                                            sp_iv_result2 = sp_iv_result2 * y;

											//cout<<"\nSP x_i variable 2 loop2\n";
										}

									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}
									}
							i++;
							}
							 i_sp=0; // reset variable

                            if(i_op == '+')
                             {
                                  x_i_result = sp_iv_result  + sp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  x_i_result = sp_iv_result -  sp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  x_i_result = sp_iv_result;
                             }
                             sp_result = sp_result * pow(x , x_i_result);

							 sp_iv_result =1; sp_iv_result2 = 0;
							 i_op='0';

					} // end of x index variable

				else if (v[i] == 'y')    // while the variable y have an index variable
					{
					    //cout<<"\nSP variable y with index";
						m++;
						i_n =1; i_m =0;
						i= i+2;
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i] - 48) ;

								}

								 sp_iv_result = const_iv;
								//cout<<"\nSP y_i constant loop1 "<<const_iv<<"\n";
								i_n++;
							}

							else if (!isdigit(v[i]) && v[i+1] != '^')
							{
								i_m++;
								if (v[i] == 'x')
								{
									//cout<<"\nSP y_i variable x loop1\n";
									sp_iv_result = sp_iv_result * x;
								}

								if (v[i] == 'y')
								{
									//cout<<"\nSP y_i variable y loop1\n";
									sp_iv_result = sp_iv_result * y;
								}

								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^' )
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}
							i++;
						}


							if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2 = 1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2 = 1;
							}

							while(v[i] != ')'  &&  i_sp ==1 )
							{
									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv * 10) + (v[i]-48) ;

										}
										sp_iv_result2 = const_iv;
										//cout<<"\nSP y_i constant loop2 "<<const_iv<<"\n";
										i_n++;
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{

										i_m++;

										if (v[i] == 'x')
										{
											sp_iv_result2 = sp_iv_result2 * x;
											//cout<<"\nSP y_i variable x loop2\n";
										}

										if (v[i] == 'y')
										{
											sp_iv_result2 = sp_iv_result2 * y;
											//cout<<"\nSP y_i variable y loop2\n";
										}

										 /* code */
									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}

										 /* code */
									}

									i++;

							}

                    i_sp=0;


                            if(i_op == '+')
                             {
                                  y_i_result = sp_iv_result  + sp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  y_i_result = sp_iv_result -  sp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  y_i_result = sp_iv_result;
                             }
                             sp_result = sp_result * pow(y , y_i_result);
                             i_op='0';

							 sp_iv_result =1; sp_iv_result2 = 0;

					}

					// for exponential e

					else if (v[i] == 'e')
					{
					   // cout<<"\nSP  Exp loop ";
						m++;
						i_m = 0;
						i_n =1;
						i= i+2;
						while(v[i] != ')' && v[i] != '+' && v[i] != '-' && i_sp != 1)
						{
							if(isdigit(v[i]))
							{
								if (i_n == 1)
								{
									const_iv =  v[i]-48;  /* code */
								}
								else
								{
									const_iv =  (const_iv * 10) + (v[i] - 48) ;

								}

								sp_iv_result = const_iv;
								//cout<<"\nSP Exp constant loop1 "<<const_iv<<"\n";
								i_n++;
							}

							else if (!isdigit(v[i]) && v[i+1] != '^' )
							{
								if (v[i] == 'x')
								{
									sp_iv_result = sp_iv_result * x;
									//cout<<"\nSP  Exp variable x loop1 ";
								}

								if (v[i] == 'y')
								{
									sp_iv_result = sp_iv_result * y;
									//cout<<"\nSP  Exp variable y loop1 ";
								}
								i_m++;
								 /* code */
							}

							else if (!isdigit(v[i]) && v[i+1] == '^')
							{
								if (v[i] == 'e')
								{

								}

								 /* code */
							}
							i++;
						}

						if (v[i] == '+')
							{
								i_op = '+';  // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2 =1;
							}
							if (v[i] == '-')
							{
								i_op = '-'; // get index operator
								i_n = 1; i_m = 0;   i_sp = 1;
								sp_iv_result2=1;
							}

							while(v[i] != ')')
							{

									if(isdigit(v[i]))
									{
										if (i_n == 1)
										{
											const_iv =  v[i]-48;  /* code */
										}
										else
										{
											const_iv =  (const_iv *10) + (v[i] -48) ;
										}

										sp_iv_result2 = const_iv;
										i_n++;
										//cout<<"\nSP Exp constant loop2 "<<const_iv<<"\n";
									}

									else if (!isdigit(v[i]) && v[i+1] != '^')
									{
										if (v[i] == 'x')
										{
											sp_iv_result2 = sp_iv_result2 * x;
										//	cout<<"\nSP  Exp variable x loop2 ";
										}

										if (v[i] == 'y')
										{
											sp_iv_result2 = sp_iv_result2 * x;
										//	cout<<"\nSP  Exp variable y loop2 ";
										}
										i_m++;
										 /* code */
									}

									else if (!isdigit(v[i]) && v[i+1] == '^')
									{
										if (v[i] == 'e')
										{

										}

										 /* code */
									}
									i++;

							}
                            if(i_op == '+')
                             {
                                  e_result = sp_iv_result  + sp_iv_result2;
                             }
                              if(i_op == '-')
                             {
                                  e_result = sp_iv_result -  sp_iv_result2;
                             }
                             if(i_op != '+' && i_op != '-')
                             {
                                  e_result = sp_iv_result;
                             }
                             sp_result = sp_result * pow(e, e_result);

							 sp_iv_result =1; sp_iv_result2 = 0;

                            i_op='0';
					}
                index =0;  // reset variable
				} // end of index loop
				else{

				}
			i++;
			}

		}while(v[i] != ';');
        sp=0;
         //cout<<"\nThis is fp result : "<<fp_result;

        //cout<<"\n is sp result : "<<sp_result;
        final_result = fp_result + sp_result;
        //cout<<"\n is sp result : "<<final_result;
            fp_result=1;  sp_result=0;
        //cin.ignore();

        }catch(int ex_value){
            if(ex_value == 1) // if ';' is omitted;
            {
              cout<<"\n\n\a\aException: no equation terminating character ';' --> error : \a"<<ex_value;
            }
            if(ex_value == 21) // if e is without index character '^'
            {
              cout<<"\n\n\a\aException: index character '^' is needed to raise a variable to power of any exponent --> error : \a"<<ex_value;
            }
            if(ex_value == 22) // if open bracket '(' is used without raise to power '^'
            {
              cout<<"\n\n\a\aException: open bracket\"(\" character can only be use to enclose index variable 'e.g e^(2x)' --> error : \a"<<ex_value;
            }
        }

        return final_result;

		}



void prog()
{
    system("cls");
    system("color 5f");
    get_equation() ;
    euler_m(a,b,row_num);
    imp_euler_m(a,b,row_num);
}


void euler_m(double x, double y, int k)
{
    double z;

     cout<<"\n\t\t****** Euler's Method Table ******\n";
     cout<<"\n\t| S/N  |  "<<setw(4)<<" Xn   |  "<<setw(4)<<" h    |  "<<setw(15)<<"  Yn  | "<<setw(15)<<"f(Xn,Yn)   | ";
    cout<<"\n\t----------------------------------------------------";
	for (int d = 0; d < k; d++)
	{
	    z = f_x_y(x,y);
		y_next = y + (h * z);

    cout<<"\n\t|  "<<d<<"   | "<<setw(4)<<x<<"   | "<<setw(4)<<h<<"   | "<<setw(10)<<y<<"   | "<<setw(10)<<z<<"   | ";
		x = x+h;
		y = y_next ;
	}
    //display(title, x , double b[k], double z[k], int k);
}
void imp_euler_m(double x, double y, int k)
{
    double p,r,q, r1,y1=y, p1;
    cout<<setprecision(9);

    cout<<"\n\n\n\t\t****** Improved Euler's Method Table ******\n";
    cout<<"\n\t| S/N  |  "<<setw(4)<<" Xn   |  "<<setw(4)<<" h    |  "<<setw(10)<<"  Yn(Eu)    | "<<setw(10)<<" Yn(Imp.Eu)  | ";
    cout<<"\n\t--------------------------------------------------------";
    for (int d = 1; d <= k; d++)
    {
        p1 = f_x_y(x,y1);
	    r1 = y1 + (h * p1);
	    y1 = r1;
	    p = f_x_y(x,y);
	    r = y + (h * p);
	    q = f_x_y(x+h, r);
		y_next = y + (h * ( (p + q) / 2 ) );
        cout<<"\n\t|  "<<d<<"   | "<<setw(4)<<x<<"   | "<<setw(4)<<h<<"   | "<<setw(10)<<r1<<"   | "<<setw(10)<<y_next<<"   | ";
		x = x+h;
		y = y_next;

	}
}



void option()
{
    system("cls");
    system("color 4b");
    int opt;
    int choice;
    cout<<"\n\t====================================================================";
    cout<<"\n\t===========[  WELCOME TO MY FINAL YEAR PROJECT PROGRAM  ]===========";
    cout<<"\n\t====================================================================\n\n";
    cout<<"\t\t1. Settings \n";
    cout<<"\t\t2. Run the program \n";
    cout<<"\t\t3. Help \n";
    cout<<"\t\t4. About \n";
    cout<<"\t\t5. Exit \n";
    cout<<"\t\tKindly choose one of the options(1,2,3,4,5) above: ";
    cin>>opt;
    switch(opt){
        case 1: setTableRow();
            break;
        case 2:   //system("cls");

                  do
                  {
                      prog();
                      cout<<endl;
                      cout<<endl;
                      cout<<"\n\t\tTo perform another program press '1' else '0' : ";
                      cin>>choice;

                  }while(choice != 0);

                    option();
                    break;

        case 3: _help();
                option();
                break;

         case 4: about();
                 option();
                 break;

         case 5: exit(1);
            break;
        default: system("cls") ; option();
    }

}

void strtofloat(string s)
{
    int nn=0, mm=1, i=0; bool flag=0;

				for(i=0; i<s.length(); i++)
                {
                     if(s[i] == '.')
                        {
                            flag=1;
                        }

                else if(isdigit(s[i]) )             // this loop gets all the number before letter
				{

					if (nn < 1)                      //
					{
						initial_v =  s[i] - 48;  /* code */
					}
					else
					{
                        if(flag==1)
                        {
                            initial_v =  initial_v + ((s[i] - 48)/pow(10,mm) ) ;
                            mm++;
                        }

                        else{
                            initial_v =  (initial_v * 10) + (s[i] - 48) ;
                        }
					}
					nn++;

				}

				else{
                        except = 1;
                      cout<<"input error : expect a number character given --> '"<<s[i]<<"' \n";
                    }

				}
}

void _help()
{
    system("cls");
    system("color 1f");
    cout<<"\n***********************************************************************************";
    cout<<"\n\n\tTo input the function or equation \n ";
    cout<<"\tAfter finish writing it add \";\" e.g \n\t y' = x + y, \t write x + y; and press enter, ";
	      cout<<"else if \n\t y' = x + e*\t write x + e^x; \n\tNote: dont add y' or dy/dx there and \n\tdont use letter other than x and y";
	      cout<<" and e for exponential\n";
	       cout<<"Note: Only 3 letters(x,y,e) is allow to be use as variable\n\n***********************************************************************************\n";

              system("pause");
}


void about()
{
    system("cls");
    system("color 1f");
    cout<<" | * |\n|  *  |\t..................................................";
    cout<<"\n | * |\t\t\t   CODE-FLAG";
    cout<<"\n|  *  |\t..................................................";
    cout<<"\n | * |\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\tProgram written by Awe Francis Olawumi";
    cout<<"\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\tEmail: awefrancolaz@gmail.com";
    cout<<"\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\tTelephone: +2349078374078";
    cout<<"\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\tYou are free to use, share and modify this program";
    cout<<"\n|  *  |\t---------------------------------------------------";
    cout<<"\n | * |\n|  *  |\tIf you modify any part of this code pls add your \n | * |\tdetails below my details and ";
    cout<<"comment your work in \n|  *  |\tthe program";
    cout<<"\n | * |\n|  *  |\t---------------------------------------------------\n";

    cout<<" | * |";
      cout<<"\n|  *  |";
     cout<<"\n | * |";
      cout<<"\n|  *  |";
     cout<<"\n | * |";
      cout<<"\n|  *  |";
     cout<<"\n | * |";
      cout<<"\n|  *  |";
     cout<<"\n | * |";
      cout<<"\n|  *  |";
     system("pause");
}
