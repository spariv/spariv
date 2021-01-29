================================================================================
                            User Manual for SPARIV
================================================================================
--------------------------------------------------------------------------------
                    SPARIV - Sparse & Matrix Library in C
--------------------------------------------------------------------------------
:Authors: Sethupathy Subramanian, Sujata Bhowmick

:Version: 1.0

:License: This work is licensed under the Creative Commons Attribution-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/ or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.

.. contents:: :depth: 2


..
 --------------------------------------------------------------------------------

Overiew
=======
SPARIV is aimed to be a self-contained matrix library with a simple syntax. The 
conversion table lists the syntax conersion for the MATLAB/Octave syntax to SPARIV.
The example codes for each function are presented in a section below and the basic
data types which are used in the SPARIV are available as, ``spariv_intt``, 
``spariv_floatt`` and ``spariv_complext``. Based on these basic data types, the
following user defined matrix data types are defined,

 - ``M_mat     - double matrix``
 - ``M_imat    - long int matrix``
 - ``M_cxmat   - double complex matrix``
 - ``M_spmat   - double sparse matrix``
 - ``M_cxspmat - double complex sparse matrix``

..
 -------------------------------------------------------------------------------

License
=======
SPARIV is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation, either version 3 
of the License, or (at your option) any later version.
 
SPARIV is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.
 
You should have received a copy of the GNU Lesser General Public
License along with SPARIV. If not, see <https://www.gnu.org/licenses/>.

..
 -------------------------------------------------------------------------------

Install
=======


..
 --------------------------------------------------------------------------------

Conversion Table
================

  ================== ==========================
    Data Type         Variables used below    
  ------------------ --------------------------
   ``M_mat``          ``A, B, C, X, AI``      
   ``M_imat``         ``row, col``      
   ``M_spmat``        ``P, Q, R, S``          
   ``double``         ``a, t1``                   
  ================== ==========================
  
  +--------------------------+---------------------------------------------+
  |      Octave              |               SPARIV                        |
  +==========================+=============================================+
  | Basic functions:                                                       |
  +--------------------------+---------------------------------------------+
  | ``A = zeros(3,3)``       | ``M_zeros(3,3, A)``                         |
  +--------------------------+---------------------------------------------+
  | ``A = randn(3,3)``       | ``M_zeros(3,3, A); M_randn(A)``             |     
  +--------------------------+---------------------------------------------+
  | ``disp(something)``      | ``M_disp(something)``                       |
  +--------------------------+---------------------------------------------+
  | ``length(A)``            | ``M_length(A)``                             |
  +--------------------------+---------------------------------------------+
  | ``size(A,1)``            | ``M_rows(A)``                               |
  +--------------------------+---------------------------------------------+
  | ``size(A,2)``            | ``M_cols(A)``                               |
  +--------------------------+---------------------------------------------+
  | ``numel(A)``             | ``M_numel(A)``                              |
  +--------------------------+---------------------------------------------+
  | ``tic``                  | ``t1 = M_tic(A)``                           |
  +--------------------------+---------------------------------------------+
  | ``toc``                  | ``M_disp( M_toc(t1) )``                     |
  +--------------------------+---------------------------------------------+
  | ``A(1,1)``               | ``_(A, 0,0)``                               |
  +--------------------------+---------------------------------------------+
  | ``A(m,n)``               | ``_(A, m-1,n-1)``                           |
  +--------------------------+---------------------------------------------+
  | ``A(3,5) = 0``           | ``_(A, 2,4) = 0``                           |
  +--------------------------+---------------------------------------------+
  | ``A(:,:) = 0``           | ``M_fill(0, A)``                            |
  +--------------------------+---------------------------------------------+
  | ``B = A``                | ``M_copy(A, B)``                            |
  +--------------------------+---------------------------------------------+
  | Linear Algebra:                                                        |
  +--------------------------+---------------------------------------------+
  | ``X = linsolve(A,B)``    | ``M_linsolve(A,B, X)``                      |
  +--------------------------+---------------------------------------------+
  | ``---``                  | ``M_xlinsolve(A,B, X, &rcondnum)``          |
  +--------------------------+---------------------------------------------+
  | ``a  = det(A)``          | ``M_det(A, &a)``                            |
  +--------------------------+---------------------------------------------+
  | ``AI = inv(A)``          | ``M_inv(A, AI)``                            |
  +--------------------------+---------------------------------------------+
  |                          || ``for(int i=0; i<M_rows(C); i++){``        |
  |                          ||   ``for(int j=0; j<M_cols(C); j++){``      |
  | ``C  = A + B``           ||     ``_(C, i,j) = _(A, i,j) + _(B, i,j);`` |
  |                          ||   ``}``                                    |
  |                          || ``}``                                      |
  +--------------------------+---------------------------------------------+
  | ``C  = A * B``           | ``M_matmul(A,B, C)``                        |
  +--------------------------+---------------------------------------------+
  | ``a  = rcond(A)``        | ``M_rcond(A, &a)``                          |
  +--------------------------+---------------------------------------------+

..
 --------------------------------------------------------------------------------

Example Codes
=============

This section of the user manual contains the example codes. Each part can be copied 
to lets say `example.c` and compile and run using,

.. code:: shell

    gcc -o exec example.c -lspariv -lopenblas; ./exec

on a Linux machine. This execution style has the liberty to choose the faster blas 
libraries, such as `openblas` which is available on the user's machine. The user 
is also free to choose the in-built albeit slower blas library by using the following 
linking of the `SPARIV`,

.. code:: shell

    gcc -o exec example.c -lsparivblas; ./exec


Linear Algebra
--------------

linsolve( )
~~~~~~~~~~~

.. code-block:: C

    #include<spariv.h>
    int main()
    {
        M_mat A=NULL, B=NULL, X=NULL;
        M_new(A); M_new(B); M_new(X);

        M_zeros( 4,4, A ); M_zeros( 4,1, B );

        //fill random numbers
        M_randn( A ); M_fill( 1, B );

        M_linsolve( A,B, X );

        M_disp( A );
        M_disp( B );
        M_disp( X );

        M_delete(A); M_delete(B); M_delete(X);
    }


det( )
~~~~~~

.. code-block:: C

    #include<spariv.h>
    int main()
    {
        M_mat A=NULL; M_new(A);
        double detA;

        //fill random numbers on 5x5 matrix
        M_zeros( 5,5, A );  M_randn( A );

        M_det( A, &detA );

        M_disp( A    );
        M_disp( detA );

        M_delete(A);
    }


inv( )
~~~~~~

.. code-block:: C

    #include<spariv.h>
    int main()
    {
        M_mat A=NULL, AI=NULL;
        M_new(A); M_new(AI);

        //fill random numbers on 5x5 matrix
        M_zeros( 5,5, A ); M_randn( A );

        M_inv( A, AI );

        M_disp( A  );
        M_disp( AI );

        M_delete(A); M_delete(AI);
    }


xlinsolve( )
~~~~~~~~~~~~

.. code-block:: C

    #include<spariv.h>
    int main()
    {
        M_mat A=NULL, B=NULL, X=NULL;
        M_new(A); M_new(B); M_new(X);

        M_zeros( 4,4, A ); M_zeros( 4,1, B );

        //fill random numbers
        M_randn( A ); M_fill( 1, B ); 

        double rcondnum;

        M_xlinsolve( A,B, X, &rcondnum );

        M_disp( A );
        M_disp( B );
        M_disp( X );
        M_disp( rcondnum );

        M_delete(A); M_delete(B); M_delete(X);
    }

..
 --------------------------------------------------------------------------------

