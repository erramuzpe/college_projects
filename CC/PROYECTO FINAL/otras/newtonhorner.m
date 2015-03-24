function [roots, iter] = newtonhorner(a,x0)
tic

0.004218
% Metodo de NEWTONHORNER
% Calcula las raices del polinomio 'a' partiendo del dato inicial x0.
% Se para para cada raiz tras 100 iter. si no hay entrada nmax o 
% si el valor absoluto de la diferencia entre dos iteraciones
% es menor que 1.e-04 (si no ha sido introducido).
% Devuelve roots e iteraciones de cada raiz.

if nargin == 2
	tol = 0.001; nmax = 1000;
end

n = length(a)-1; 
roots = zeros(n,1);
iter = zeros(n,1);

for k = 1:n
	%Empieza Newton
	niter =0;
	x = x0;
	diff = tol + 1;
	while niter <= nmax & diff >= tol
		[pz, b] = horner(a,x);   %% valor en el punto
		[dpz, b] = horner(b,x);  %%valor en la derivada
		xnew = x - pz/dpz;       %%newton
		diff = abs(xnew-x);
		niter = niter+1;
		x=xnew;
	end
	if niter >= nmax
		fprintf('no converge, superado nmax');
	end
	[pz,a] = horner(a,x);
	roots(k) = x;
	iter(k) = niter;
end
toc
return

