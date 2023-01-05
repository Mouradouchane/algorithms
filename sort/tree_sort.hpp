
#pragma once 

namespace sort {

	// anonymous namespace
	namespace {

		// node template class to build binary tree
		template<typename t> class NODE {

			public : 
				bool is_empty = true; // to avoid 0 == NULL problems
				t value = NULL; // node value
				NODE<t>* left = nullptr; // left node
				NODE<t>* right = nullptr; // right node

				// def constructor
				NODE() { }

				// constructor 1
				NODE(t const& value , NODE * left  , NODE * right) 
					:value{ value }, left{ left }, right{right} // init list
				{ 
					is_empty = false;
				}

				// constructor 2
				NODE(t const& value) 
					:value{ value } // init list 
				{
					is_empty = false;
				}

				// def destructor
				~NODE(){ 
				
					// destruct left node if it's not empty
					if (this->left  != nullptr) this->left->~NODE();
					// destruct right node if it's not empty
					if (this->right != nullptr) this->right->~NODE();

				}

		}; // end of class NODE

		// o( log n )
		// function to insert_process element's from array to binary tree
		template<typename t> static void insert_process( 
			NODE<t> * node , 
			t const& new_value , 
			bool (* const& compare_function)(t const& target , t const& other_element)
		){

			// if node is empty insert on it
			if (node->value == NULL && node->is_empty) {
				node->value = new_value;
				return;
			}

			// if new_value is bigger than the value in the current node
			if ( compare_function(node->value, new_value) ) {

				// insert in right node if it empty
				if (node->right == nullptr) node->right = new NODE<t>(new_value);

				// otherwise "go right"
				else insert_process<t>(node->right, new_value, compare_function);

			}
			// if new_value is smaller than the value in the current node
			else { 

				// insert in left node if it empty
				if (node->left == nullptr) node->left = new NODE<t>(new_value);

				// otherwise "go left"
				else insert_process<t>(node->left, new_value, compare_function);

			}

		} // end of insert_process function

		// o( n log n )
		// recursive function to travle around the binary tree and put back sorted elements in array
		template<typename t> void sort_process(
			t * arr , // origin array
			NODE<t> * node , // node from binary tree to check
			size_t & index // start index in array
		) {

			// high priority to the left node
			// soo if there's a left node go it first
			if (node->left != nullptr) sort_process<t>( arr , node->left , index );

			// put target element in target index poisition in array
			arr[index] = node->value;
			// increment index
			index += 1;

			// then go to right node if there's a right node
			if(node->right != nullptr) sort_process<t>( arr , node->right , index );


		} // end of sort_process function


		// testing function to log tree in console
		/*
		template<typename t> static void print_binary_tree(
			NODE<t>* node,
			size_t tab = 1
		) {

			if (node->right != nullptr) print_binary_tree<t>(node->right, tab + tab);


			for (size_t i = 1; i <= tab; i += 1) std::cout << '\t';
			std::cout << node->value << '\n';

			if (node->left != nullptr) print_binary_tree<t>(node->left, tab + tab);

		}
		*/

	} // end of anonymous namespace

	// o( n log n )
	template<typename t> void tree_sort(
		t * arr , // target array as pointer
		size_t const& start_index , 
		size_t const& end_index , 
		// function to compare elements
		bool (* const& compare_function)(t const& target , t const& other_element) 
	){
		
		// define root as binary tree to insert_process elements on it later for sort process 
		// just a simple binary tree is enough , no need for fancy tree
		NODE<t> * root  = new NODE<t>();

		// start insert_process element in binary tree
		for (size_t i = start_index; i <= end_index; i += 1) {

			insert_process<t>(root, arr[i], compare_function);
			 
		}


		// now start traversal and sorting process
		// start from start_index 
		size_t i = start_index;
		sort_process<t>(arr, root, i);

		// delete binary tree from heap
		delete root;

	} // end of tree_sort algorithm


} // end of namespace sort