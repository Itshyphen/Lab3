%Solution of 5A
x = [2,5;4,6];
y = [1,5;6,-2];

for m = 1:2
  for n = 1:2
    z(m,n)=x(m,n)+y(m,n);
  endfor
endfor
%print output
z


% while loop execution
m=1; 
while( m <= 2 )
  n=1;
  while( n <=2 )
    z(m,n)=x(m,n)+y(m,n);
    n+=1;
  endwhile
  m+=1;
endwhile

%print output
z

z=x+y

%Solution of 5B

a = 15;
x;

if a>0
  x = 5;
else
  x = 100;
endif
%print output
x

