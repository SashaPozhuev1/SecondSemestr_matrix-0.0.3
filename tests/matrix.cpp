#include <catch.hpp>
#include <sstream>

#include "matrix.hpp"

TEST_CASE("creating matrix")
{
    matrix_t<double> matrix;
    REQUIRE( matrix.rows() == 0 );
    REQUIRE( matrix.collumns() == 0 );
}

TEST_CASE("reading matrix")
{
    std::string input{
        "3, 3\n"
        "1.1f 1f 1f\n"
        "2f 2.2f 2f\n"
        "3f 3f 3.3f" };
    matrix_t<float> matrix;
    std::istringstream istream{ input };
    
    REQUIRE( matrix.read( istream ) );
    REQUIRE( matrix.rows() == 3 );
    REQUIRE( matrix.collumns() == 3 );
    
    std::ostringstream ostream;
    matrix.write( ostream );
    
    REQUIRE( input == ostream.str() );
}

TEST_CASE("add matrix")
{
    std::string stroka1{
        "3, 4\n"
        "1.1f 1f 4f 5f\n"
        "2f 1.2f 2f 6f\n"
        "9f 3f 3.3f 7f" }; 
    std::string stroka2{
        "3, 4\n"
        "7.1f 2f 2f 7f\n"
        "1f 5.2f 2f 6f\n"
        "2f 2f 8.3f 5f" };
    std::string strokar{
        "3, 4\n"
        "8.2f 3f 6f 12f\n"
        "3f 6.4f 4f 12f\n"
        "11f 5f 11.6f 12f" };
    
    matrix_t<float> matrix1;
    matrix_t<float> matrix2;
    matrix_t<float> result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 + matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("sub matrix")
{
    std::string stroka1{
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    std::string stroka2{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string strokar{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    
    matrix_t<int> matrix1, matrix2, result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 - matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("mul matrix")
{
    std::string stroka1{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "4, 3\n"
        "7 2 2 \n"
        "1 5 2 \n"
        "2 2 8 \n" 
        "1 1 1" };
    std::string strokar{
        "3, 3\n"
        "21 20 41\n"
        "25 19 28\n"
        "79 46 55" };
    
    matrix_t<int> matrix1, matrix2, result;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    result = matrix1 * matrix2;
    
    std::ostringstream ostream;
    result.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfsub matrix")
{
    std::string stroka1{
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    std::string stroka2{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string strokar{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    
    matrix_t<int> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 -= matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfadd matrix")
{
    std::string stroka1{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "3, 4\n"
        "7 2 2 7\n"
        "1 5 2 6\n"
        "2 2 8 5" };
    std::string strokar{
        "3, 4\n"
        "8 3 6 12\n"
        "3 6 4 12\n"
        "11 5 11 12" };
    
    matrix_t<int> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 += matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}

TEST_CASE("selfmul matrix")
{
    std::string stroka1{
        "3, 4\n"
        "1 1 4 5\n"
        "2 1 2 6\n"
        "9 3 3 7" }; 
    std::string stroka2{
        "4, 3\n"
        "7 2 2 \n"
        "1 5 2 \n"
        "2 2 8 \n" 
        "1 1 1" };
    std::string strokar{
        "3, 3\n"
        "21 20 41\n"
        "25 19 28\n"
        "79 46 55" };
    
    matrix_t<int> matrix1, matrix2;   
    std::istringstream istream1{ stroka1 };
    std::istringstream istream2{ stroka2 };
    
    matrix1.read( istream1 );
    matrix2.read( istream2 );
    
    matrix1 *= matrix2;
    
    std::ostringstream ostream;
    matrix1.write( ostream );
    
    REQUIRE( strokar == ostream.str() );
}
