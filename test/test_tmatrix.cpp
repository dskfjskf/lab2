#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> v1(5), v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> v1(5), v2(v1);
	EXPECT_NE(&v1[0][0], &v2[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> v(4);
	EXPECT_EQ(4, v.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> v(4);
	v[0][0] = 4;

	EXPECT_EQ(4, v[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[-3]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> v(4);
	ASSERT_ANY_THROW(v[8]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> v(4);
	v = v;
	ASSERT_NO_THROW();
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> v1(4), v2(4);
	v1[1] = v1[1]*0;
	v2 = v1;
	EXPECT_EQ(v1, v2); 
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> v1(4), v2(9);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> v1(4), v2(9);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> v1(4), v2(v1);
	EXPECT_EQ(true, v1 == v2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> v1(4);
	EXPECT_EQ(true, v1 == v1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> v1(2), v2(3);
	EXPECT_NE(v1, v2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	const int s = 5;
	TMatrix<int> v1(s), v2(s), v3(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = v1[i]*0+i;
		v2[i] = v2[i]*0+1;
		v3[i] = v1[i] + v2[i];
	}
	v1 = v2 + v1;
	EXPECT_EQ(v1, v3);
}

TEST(TMtrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> v1(5), v2(9);
	ASSERT_ANY_THROW(v2 + v1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	const int s = 5;
	TMatrix<int> v1(s), v2(s), v3(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] =v1[i]*0+ i;
		v2[i] = v2[i]*0+i*i;
		v3[i] = v2[i] - v1[i];
	}
	v1 = v2 - v1;
	EXPECT_EQ(v1, v3);
}


TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix<int> v1(5), v2(9);
  ASSERT_ANY_THROW(v2 - v1);
}

