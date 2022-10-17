
#pragma once 

namespace sort {

	// anonymous namespace
	namespace {

		template<typename t> class NODE {

			public : 

				t value = NULL;
				NODE* left = nullptr;
				NODE* right = nullptr;

				// def constructor
				NODE() { }

				// constructor 1
				NODE(t const& value , NODE * left  , NODE * right) 
					:value{ value }, left{ left }, right{right} // init list
				{ 

				}

				// constructor 2
				NODE(t const& value) :value{ value } // init list 
				{

				}

				// def destructor
				~NODE(){  }

		}; // end of class NODE

		// o( log n )
		// function to insert element's from array to tree
		template<typename t> static void insert( 
			NODE<t> * NODE , 
			t & new_value , 
			bool (* const& compare_function)(t const& target , t const& other_element)
		){

			if (NODE->value == NULL) {
				NODE->value = new_value;
				return;
			}

			if ( compare_function(NODE->value, new_value) ) {

				if (NODE->right == nullptr) NODE->right = new NODE<t>(new_value);
				else insert<t>(NODE->right, new_value, compare_function);

			}
			else {

				if (NODE->left == nullptr) NODE->left = new NODE<t>(new_value);
				else insert<t>(NODE->left, new_value, compare_function);

			}

		}

	} // end of anonymous namespace


	template<typename t> void tree_sort(
		t * arr , // target array as pointer
		size_t const& start_index , 
		size_t const& end_index , 
		// function to compare elements
		bool (* const& compare_function)(t const& target , t const& other_element) 
	){
		
		// define binary tree 
		NODE<t> * root;

		// insert element in tree
		for (size_t i = start_index; i <= end_index; i += 1) {

			insert<t>(root, arr[i], compare_function);

		}

	} // end of tree_sort algorithm


} // end of namespace sort