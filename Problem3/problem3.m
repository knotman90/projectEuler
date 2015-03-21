function p=problem3(n)
	% the algorithm is based on the fundamental theorem of arithmetic 
	% p will be the largest prime factor of the number n 
	m=n;
	p=0;
	oldp=2;
	while (oldp*oldp <= m )
	         if (mod(m,oldp)==0)
	         	m=m/oldp;
	         	p=oldp;
	         else 
	         	oldp ++;
	         end
	   end
	   if (m > p )
	      p=m;
	    end 
	        
	      	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	%m=0;
	%i=2;
	%while (i < n )
	          %if mod(n,i)==0 
	               % j=2;
	               %cont= true ;
	              % while ( j< i )
	               	%if mod(i,j)==0
	               	    %cont = false;
	               	    % break	
	               	%  end
	               	%  j++; 
	                 %end
	                % if cont == true
	                 	%m=i;
	                 %end
	              %end
	           %i++;
	    % end 	