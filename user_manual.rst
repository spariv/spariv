================================================================================
                            User Manual for SPARIV
================================================================================
--------------------------------------------------------------------------------
                    SPARIV - Sparse & Matrix Library in C
--------------------------------------------------------------------------------
:Authors: Sethupathy Subramanian, Sujata Bhowmick

:Version: 1.0

.. contents:: :depth: 2

..
 -------------------------------------------------------------------------------

Install
=======

..
 --------------------------------------------------------------------------------

Conversion Table
================
  
  +--------------------------+---------------------------------------------+
  |      Octave              |               SPARIV                        |
  +==========================+=============================================+
  | ``X = linsolve(A,B)``    | ``M_linsolve(A,B, X)``                      |
  +--------------------------+---------------------------------------------+
  | ``---``                  | ``M_xlinsolve(A,B, X, &rcondnum)``          |
  +--------------------------+---------------------------------------------+
  | ``detA = det(A)``        | ``M_det(A, &detA)``                         |
  +--------------------------+---------------------------------------------+
  |                          || ``for(int i=0; i<nrows; i++){``            |
  |                          ||   ``for(int i=0; i<nrows; i++){``          |
  | ``C = A + B``            ||     ``_(C, i,j) = _(A, i,j) + _(B, i,j);`` |
  |                          ||   ``}``                                    |
  |                          || ``}``                                      |   
  +--------------------------+---------------------------------------------+
  | ``C = A * B``            | ``M_matmul(A,B, C)``                        |
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

