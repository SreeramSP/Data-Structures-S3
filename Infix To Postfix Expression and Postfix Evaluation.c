//Infix To Postfix Expression and Postfix Evaluation//
//Sreeram SP//

#include <stdio.h>
#include <string.h>
#include <math.h>
struct pfix
{
  float value;
  char operand;
};

void push2(float);
void analyze(char);
void post(char);
void push(char);
void ev(char);
char pop();
float pop2();
float numerical_value(char);
void eval();
int i=0,j=0,top=-1,top2=-1,p=-1,f=-1,count=0;
float stack2[100];
char infix[100],postfix[100],stack[100],temp[100],evaluate[100];
struct pfix pf[30];

void main()
{
  temp[0]='#';
  printf("Enter the infix expression= ");
  gets(infix);
  strcat(infix,"#");
  strcat(temp,infix);
  strcpy(infix,temp);
  while(infix[i]!='\0')
  {
     analyze(infix[i]);
     i++;
  }
  printf("POSTFIX EXPRESSION:");
  puts(postfix);
  eval();
}

void analyze(char symbol)
{
  if(symbol=='#'||symbol=='*'||symbol=='+'||symbol=='-'||symbol=='('||symbol==')'||symbol=='/'||symbol=='^')
    push(symbol);
  else
  {
    f++;
    evaluate[f]=symbol;
    post(symbol);
  }
}

void post(char operand)
{
  p++;
  postfix[p]=operand;
}

void push(char operator)
{

  char t;


  if(operator=='#')
  {
    if(i!=0)
    {
      while(j<10)
      {
        t=pop();
        if(t=='#')
          break;
        post(t);
      }
    }
    else
    {
      top++;
      stack[top]=operator;
    }
  }


  else if(operator=='(')
  {

    top++;
    stack[top]=operator;
  }
  else if(operator==')')
  {

    while(j<10)
    {
      t=pop();
      if(t=='(')
        break;
      post(t);

    }
  }

    else if(operator=='/'||operator=='*')
    {
      if(stack[top]=='/'||stack[top]=='*'||stack[top]=='^')
      {

        post(pop());
      }
      top++;
      stack[top]=operator;
    }
    else if(operator=='^')
    {
      if(stack[top]=='^')
      {

        post(pop());
      }
      top++;
      stack[top]=operator;
    }

    else if(operator=='+'||operator=='-')
      {
        if(top!=-1&&(stack[top]=='+'||stack[top]=='-'||stack[top]=='/'||stack[top]=='*'||stack[top]=='^'))
        {

          post(pop());
        }
        top++;
        stack[top]=operator;
      }

      else
        printf("UNEXPECTED ERROR\n");

  }


char pop()
{

  char t2=stack[top];
  top--;
  return(t2);
}

void eval()
{

  for(int m=0;m<=f;m++)
  {
    printf("Enter the value of %c ",evaluate[m]);
    scanf("%f",&pf[m].value);
    pf[m].operand=evaluate[m];
    count++;
  }
  p++;
  postfix[p]='#';
  int q=0;
  while(postfix[q]!='#')
  {
    ev(postfix[q]);
    q++;
  }
  printf("%f\n",stack2[0]);
}


void ev(char e)
{

  if(e!='*'&&e!='+'&&e!='-'&&e!='('&&e!=')'&&e!='/'&&e!='^')
    push2(numerical_value(e));
  else
  {
    if(e=='+')
        push2(pop2()+pop2());
    else if(e=='-')
    {
        float o1=pop2();
        float o2=pop2();
        push2(o2-o1);
    }
    else if(e=='*')
        push2(pop2()*pop2());
    else if(e=='/')
    {
        float o1=pop2();
        float o2=pop2();
        push2(o2/o1);
    }
    else
    {
        float o1=pop2();
        float o2=pop2();
        push2(pow(o2,o1));
    }
  }
}

void push2(float c1)
{
  top2++;
  stack2[top2]=c1;
}

float pop2()
{
  float t1=stack2[top2];
  top2--;
  return t1;
}


float numerical_value(char c2)
{
  int u;
  for(u=0;u<count;u++)
  {
    if (pf[u].operand==c2)
      break;
  }
  return pf[u].value;
}
