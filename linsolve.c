/*----------------------------------------------------------------------------*
 *                 SPARIV - Sparse and Matrix Library in C
 *  Authors: Sethupathy S. & Sujata B.
 *----------------------------------------------------------------------------*/

/* * *
 *
 *  Copyright (c) 2011-2020 Sethupathy Subramanian
 *  Copyright (c) 2019-2020 Sujata Bhowmick
 *
 *  All rights reserved.
 *
 *  This file is part of SPARIV.
 *
 *  SPARIV is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as 
 *  published by the Free Software Foundation, either version 3 of 
 *  the License, or (at your option) any later version.
 *
 *  SPARIV is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public 
 *  License along with SPARIV. If not, see <https://www.gnu.org/licenses/>.
 *
 * * */

#include<spariv.h>
#include<stdlib.h>

int main()
{
    // M_mat - double matrix
    M_mat A=NULL, B=NULL, X=NULL;  
    M_new(A); M_new(B);  M_new(X);  

    // Defining the sizes of A, B
    M_zeros(4,4, A);  
    M_zeros(4,1, B);

    M_randn(A);        
    M_fill(1.0, B);    
    M_linsolve(A,B, X); 

    M_disp(A); 
    M_disp(B);
    M_disp(X);

    M_delete(A); M_delete(B); M_delete(X);
}
