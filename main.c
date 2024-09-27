#include<math.h>
#include <stdio.h>
#include<stdlib.h>
void inverse (float a[3][3]);
float det (float a[3][3]);
float lu (float a[2][2]);
float lu1 (float a[3][3]);
float eigen (float a[3][3]);
int main ()
{
  float a[2][2];
  float b[3][3];
 int i, j, r, c, a_1;
  printf("enter order of matrix \nnumber of row s :");
  scanf ("%d", &r);
  printf("number of columns :");
  scanf ("%d", &c);
 
  if (r == c && r == 3)
    {
         printf("enter elements of matrix :");
      for (i = 0; i < 3; i++){
          for (j = 0; j < 3; j++)
	    {
	      scanf ("%f", &b[i][j]);
	    }
	} 
	
	while(1){
	    printf("\n\nchoose 1 for inverse of matrix\n");
	printf("choose 2 for LU decomposition of matrix\n");
	printf("choose 3 for Eigen values of matrix\n");
	printf("choose 4 for Deteminant of matrix\n");
	printf("choose 5 to exit\n\n\n");
	scanf("%d",&a_1);
	switch(a_1){
	    case 1:inverse(b);break;
	   	case 2:lu1(b);break;
	    case 3:eigen(b);break;
	    case 4:printf("Determinent of matrix is %f",det(b)); break;
	    case 5:exit(0);
        default :printf("invalid choice");
	}}
	   
   }
  else if (r == c && r == 2)
    {
        printf("enter elements of matrix :");
      for (i = 0; i < 2; i++)
	{
	  for (j = 0; j < 2; j++)
	    {
	      scanf ("%f", &a[i][j]);
	    }
}	
      lu (a);
    }
  else if(r==c&&c!=2&&c!=3)
    printf ("calculation not possible by this code");
    else
    printf("not a square matrix");


}

float
lu (float a[2][2])
{
  float u[2][2], l[2][2];
  int i, j;
  u[0][0] = a[0][0];
  u[0][1] = a[0][1];
  u[1][0] = 0;
  l[0][0] = 1;
  l[1][1] = 1;
  l[0][1] = 0;
  l[1][0] = a[1][0] / u[0][0];
  u[1][1] = a[1][1] - (l[1][0] * u[0][1]);

  printf ("\nl matrix :\n");
  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  printf ("%.4f  ", l[i][j]);
	}
      printf ("\n");
    }

  printf ("\n u matrix :\n");

  for (i = 0; i < 2; i++)
    {
      for (j = 0; j < 2; j++)
	{
	  printf ("%.4f  ", u[i][j]);
	}
      printf ("\n");
    }



}

float
lu1 (float a[3][3])
{
  float l[3][3], u[3][3];
  int i, j;
  l[0][0] = 1;
  l[0][1] = 0;
  l[0][2] = 0;
  l[1][1] = 1;
  l[1][2] = 0;
  l[2][2] = 1;
  u[1][0] = 0;
  u[2][0] = 0;
  u[2][1] = 0;
  u[0][0] = a[0][0];
  u[0][1] = a[0][1];
  u[0][2] = a[0][2];
  l[1][0] = a[1][0] / u[0][0];
  l[2][0] = a[2][0] / u[0][0];
  u[1][1] = a[1][1] - (l[1][0] * u[0][1]);
  l[2][1] = (a[2][1] - l[2][0] * u[0][1]) / u[1][1];
  u[1][2] = a[1][2] - (l[1][0] * u[0][2]);
  u[2][2] = a[2][2] - u[0][2] * l[2][0] - u[1][2] * l[2][1];

  printf ("l matrix :\n");
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%.2f ", l[i][j]);
	}
      printf ("\n");
    }

  printf ("u matrix :\n");
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%.2f ", u[i][j]);
	}
      printf ("\n");
    }


}

void
inverse (float a[3][3])
{
  float temp[3][3], b[3][3];
  float k;
  int i, j;
  k = det (a);
  if(k!=0){
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  temp[i][j] = a[i][j];
	}
    }
  //row 1
  a[0][0] = temp[1][1] * temp[2][2] - temp[2][1] * temp[1][2];
  a[0][1] = -(temp[1][0] * temp[2][2] - temp[2][0] * temp[1][2]);
  a[0][2] = temp[1][0] * temp[2][1] - temp[2][0] * temp[1][1];
  //row 2
  a[1][0] = -(temp[0][1] * temp[2][2] - temp[2][1] * temp[0][2]);
  a[1][1] = temp[0][0] * temp[2][2] - temp[2][0] * temp[0][2];
  a[1][2] = -(temp[0][0] * temp[2][1] - temp[0][1] * temp[2][0]);
  //row 3
  a[2][0] = temp[0][1] * temp[1][2] - temp[0][2] * temp[1][1];
  a[2][1] = -(temp[0][0] * temp[1][2] - temp[0][2] * temp[1][0]);
  a[2][2] = temp[1][1] * temp[0][0] - temp[1][0] * temp[0][1];
//tranpose of cofactor matrix
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  b[i][j] = a[j][i];
	}
    }
  printf ("inverse matrix\n");
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  printf ("%.4f  ", b[i][j] * (1.0 / (float) k));
	}
      printf ("\n");
    }
}
    else 
    printf("Inverse is not possible");
}


float
det (float a[3][3])
{
  int d;
  d =
    a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) -
    a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) +
    a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
  return d;
}

float
eigen (float a[3][3])
{
  int i, j, d, k, f_x, b[10], o = 0, x, v, e;
  float w, q;
  float x1, y1;
  d = det (a);
  k = (a[1][1] * a[2][2] - a[2][1] * a[1][2]) +
    (a[0][0] * a[2][2] - a[2][0] * a[0][2]) + (a[0][0] * a[1][1] -
					       a[1][0] * a[0][1]);
  v = a[0][0] + a[1][1] + a[2][2];

  for (x = -100; x <= 100; x++)
    {
      f_x = (x * x * x) - (x * x * v) + (x * k) - d;
      if (f_x == 0)
	{
	  b[o] = x;
	  o++;
	}

    }
  printf ("Eigen values are\n");
  for (i = 0; i < o; i++)
    {

      printf ("Eigen value %d is %d\n", i + 1, b[i]);
    }
  if (i == 1)
    {
       
      k = (a[1][1] * a[2][2] - a[2][1] * a[1][2]) +
	(a[0][0] * a[2][2] - a[2][0] * a[0][2]) + (a[0][0] * a[1][1] -
						   a[1][0] * a[0][1]);
      v = a[0][0] + a[1][1] + a[2][2];
     
      if (b[0] < 0)
	{
	  b[0] = -b[0];
	}
      else if (b[0] == 0)
	{
	  b[0] = 0;
	}
	//x^2 +(b[0]-v)+((b[0]-v)b[0]+k) there fore roots of quadratic equations
	 w = b[0] - v;
      q = (w * b[0]) + k;
      float deter;
      float _ans= w * w - (4 * q);
      if(_ans<0)
      deter = sqrt (-_ans);
      else
      deter = sqrt(_ans);
      
   
      if (_ans > 0.0)
	{
	  x1 = (-w + deter) / 2.0;
	  y1 = (-w - deter) / 2.0;
	  printf ("Eigen value %d is %f\n", o + 1, x1);
	  
	  printf ("Eigen value %d is %f", o + 2, y1);
	}
      else if (_ans == 0.0)
	{
	  x1 = (-w + deter) / 2.0;

	  printf ("Eigen values %d ,%d is %f", o + 1, o + 2, x1);

	}
      else if (_ans < 0.0)
	{
	  printf ("remaining eigen values are Imaginary\n");

	  x1 = -w / 2.0;
	  y1 = deter / 2.0;
	  if (x1==-0){
	      x1=0;
	  }
	  if(y1>=0)
	  printf ("imaginary eigen values are :\neigenvalue %d is %.2f + %.2fi\neigen value %d is %.2f - %.2fi", o + 1, x1, y1, o + 2, x1, y1);
else
printf ("imaginary eigen values are :\neigenvalue %d is %.2f + %.2fi\neigen value %d is %.2f - %.2fi", o + 1, x1, -y1, o + 2, x1, -y1);
	}
    }
}






