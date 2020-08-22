
---------------------------------------
 SPARIV - Sparse & Matrix Library in C 
---------------------------------------

Language   : C11
License    : LGPLv3
Dependency : BLAS

 - A Sparse & Matrix library written in C language and compatible with C++
 - Syntax similar to  MATLAB®/Octave
 - Integrated with Lapack, SuperLU and optionally integrated with BLAS
 - Faster development with explicit error messages 

----------------------------------------
Syntax Conversion:
----------------------------------------
M_mat     : double matrix
M_imat    : long matrix
M_cxmat   : double complex matrix
M_spmat   : sparse double matrix
M_spcxmat : sparse double complex matrix

----------------------------------------
Syntax Conversion:
----------------------------------------
M_mat     : A, B, C, AI, AT, X
double    : a, t1
----------------------------------------
     Octave        -      SPARIV
----------------------------------------

A = zeros(3,3)  . . . . . . .  M_zeros(3,3, A)
 
A = randn(3,3)  . . . . . . .  M_zeros(3,3, A); M_randn(A)

disp(something) . . . . . . .  M_disp(something)

length(A) . . . . . . . . . .  M_length(A)

size(A,1) . . . . . . . . . .  M_rlen(A)     [ row length ]

size(A,2) . . . . . . . . . .  M_clen(A)     [ column length ]

row upper limit . . . . . . .  M_rlim(A)     [ defined as: M_rlen(A)-1 ]

col upper limit . . . . . . .  M_clim(A)     [ defined as: M_clen(A)-1 ]

tic . . . . . . . . . . . . .  t1 = M_tic()

toc . . . . . . . . . . . . .  disp( M_toc(t1) )

A(1,1)  . . . . . . . . . . .  _(A,0,0)  

A(n,n)  . . . . . . . . . . .  _(A,n-1,n-1) 

A(3,5) = 0  . . . . . . . . .  _(A,2,4) = 0

A(:,:) = 0  . . . . . . . . .  M_fill(0, A)

B(:,:) = A(:,:) . . . . . . .  M_copy(A, B)

C = A+B . . . . . . . . . . .  for(int i=0; i<M_rlen(A); i++){
                                   for(int j=0; j<M_clen(A); j++){
                                       _(C,i,j) = _(A,i,j) + _(B,i,j);
                                   }
                               }

B = -A  . . . . . . . . . . .  M_minus(A, B)

B = abs(A)  . . . . . . . . .  M_abs(A, B)

a = sum(sum(A)) . . . . . . .  a = M_sum(A)

a = min(min(A)) . . . . . . .  a = M_min(A)

a = max(max(A)) . . . . . . .  a = M_max(A)

