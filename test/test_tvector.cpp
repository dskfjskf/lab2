#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);
  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(5);
	v1 = v1 + 1;
	TVector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(5), v2(v1);
	EXPECT_NE(&v1[0], &v2[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);
  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);
  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[8]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	v = v;
	ASSERT_NO_THROW();
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(4),v2(4);
	v1 = v1 + 1;
	v2 = v1;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(4), v2(9);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v1(4), v2(9);
	v1 = v2;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(4), v2(v1);
	EXPECT_EQ(true,v1==v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v1(4);
	EXPECT_EQ(true, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(2), v2(3);
	EXPECT_NE(v1, v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	const int s1 = 5, s2 = 5, k = 3;
	TVector<int> v1(s1), v2(s2);
	for (int i = 0; i < s1; i++)
	{
		v1[i] = i;
		v2[i] = v1[i] + k;
	}
	v1=v1 + k;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	const int s = 5, k = 3;
	TVector<int> v1(s), v2(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = i;
		v2[i] = v1[i] + k;
	}
	v2 = v2 - k;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	const int s= 5, k = 3;
	TVector<int> v1(s), v2(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = i;
		v2[i] = v1[i] * k;
	}
	v1 = v1*k;
	EXPECT_EQ(v1, v2);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	const int s = 5;
	TVector<int> v1(s), v2(s), v3(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] =  i;
		v2[i] =  1;
		v3[i] = v1[i] + v2[i];
	}
	v1=v2+v1;
	EXPECT_EQ(v1, v3);  
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(9);
	ASSERT_ANY_THROW(v2+v1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	const int s = 5;
	TVector<int> v1(s), v2(s), v3(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] =i;
		v2[i] = i*i;
		v3[i] = v2[i] - v1[i];
	}
	v1 = v2 - v1;
	EXPECT_EQ(v1, v3);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(5), v2(9);
	ASSERT_ANY_THROW(v2 - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	const int s = 5;
	int r = 0;
	TVector<int> v1(s), v2(s);
	for (int i = 0; i < s; i++)
	{
		v1[i] = i;
		v2[i] = i+2;
		r += v1[i] * v2[i];
	}
	
	EXPECT_EQ(v1*v2, r);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  const int s1 = 5, s2 = 9;
  TVector<int> v1(s1), v2(s2);
  ASSERT_ANY_THROW(v2*v1);
}
