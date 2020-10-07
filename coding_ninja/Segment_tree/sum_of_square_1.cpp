#include<bits/stdc++.h>
using namespace std;

struct Node_t{
	int sum_of_squares;
	int sum;
};

struct Node_l{
	int value;
	int type;
};

void buildTree(int *arr, Node_t* tree, int start, int end, int currPos){
	
	if(start == end){
		tree[currPos].sum = arr[start];
		tree[currPos].sum_of_squares = arr[start] * arr[start];
		return;
	}

	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2*currPos);
	buildTree(arr, tree, mid + 1, end , 2* currPos + 1);

	tree[currPos].sum_of_squares = tree[2*currPos].sum_of_squares + tree[2*currPos+1].sum_of_squares;
	tree[currPos].sum = tree[2* currPos].sum + tree[2*currPos +1].sum;
}

void updateLazy(Node_t* tree, Node_l* lazy, int start, int end, int startR, int endR, int currPos, int value, int choice){

	if(start > end){
		return;
	}

	if(lazy[currPos].type != 0){
		if(lazy[currPos].type == 1){
            tree[currPos].sum += lazy[currPos].value * (end - start + 1);
			tree[currPos].sum_of_squares += 2 * lazy[currPos].value * tree[currPos].sum + lazy[currPos].value * lazy[currPos].value *(end - start + 1);

			if(start != end){
				lazy[2*currPos].type = lazy[2*currPos].type == 2 ? 2 : 1;
                lazy[2*currPos].value += lazy[currPos].value;
                lazy[2*currPos+1].type = lazy[2*currPos].type == 2 ? 2 : 1;
                lazy[2*currPos+1].value += lazy[currPos].value; 
			}
		}
		else if(lazy[currPos].type == 2){
            tree[currPos].sum = lazy[currPos].value * (end - start + 1);
			tree[currPos].sum_of_squares = lazy[currPos].value * lazy[currPos].value *(end - start + 1);

			if(start != end){
				lazy[2*currPos].type = 2;
                lazy[2*currPos].value = lazy[currPos].value;
                lazy[2*currPos+1].type = 2;
                lazy[2*currPos+1].value = lazy[currPos].value; 
			}
		}
		lazy[currPos].value = 0;
		lazy[currPos].type = 0;
	}

	if(startR > end || endR < start){
		return;
	}

	if(startR <= start && endR >= end){

		if(choice == 1){
			tree[currPos].sum_of_squares += 2 * value * tree[currPos].sum + value * value *(end - start + 1);
            tree[currPos].sum += value * (end - start + 1);
			

			if(start != end){
				lazy[2*currPos].type = lazy[2*currPos].type == 2 ? 2 : 1;
	            lazy[2*currPos].value += value;
	            lazy[2*currPos+1].type = lazy[2*currPos].type == 2 ? 2 : 1;;
	            lazy[2*currPos+1].value += value; 
			}
		}
		else if(choice == 2){
            tree[currPos].sum = value * (end - start + 1);
			tree[currPos].sum_of_squares = value * value *(end - start + 1);

			if(start != end){
				lazy[2*currPos].type = 2;
	            lazy[2*currPos].value = value;
	            lazy[2*currPos+1].type = 2;
	            lazy[2*currPos+1].value = value; 
			}
		}

		return;
	}

	int mid = (start + end)/2;
	updateLazy(tree, lazy, start, mid, startR, endR, 2* currPos, value, choice);
	updateLazy(tree, lazy, mid + 1, end,startR, endR ,2 * currPos + 1, value, choice);
	tree[currPos].sum_of_squares = tree[2*currPos].sum_of_squares + tree[2*currPos+1].sum_of_squares;
	tree[currPos].sum = tree[2*currPos].sum + tree[2*currPos+1].sum;
}

int queryLazy(Node_t* tree, Node_l* lazy, int start, int end, int left, int right, int currPos){

	if(start > end){
		return 0;
	}

	if(lazy[currPos].type != 0){
		if(lazy[currPos].type == 1){
            tree[currPos].sum += lazy[currPos].value * (end - start + 1);
			tree[currPos].sum_of_squares += 2 * lazy[currPos].value * tree[currPos].sum + lazy[currPos].value * lazy[currPos].value *(end - start + 1);

			if(start != end){
				lazy[2*currPos].type = lazy[2*currPos].type == 2 ? 2 : 1;
                lazy[2*currPos].value += lazy[currPos].value;
                lazy[2*currPos+1].type = lazy[2*currPos].type == 2 ? 2 : 1;
                lazy[2*currPos+1].value += lazy[currPos].value; 
			}
		}
		else if(lazy[currPos].type == 2){
			tree[currPos].sum_of_squares = lazy[currPos].value * lazy[currPos].value *(end - start + 1);
			tree[currPos].sum = lazy[currPos].value * (end - start + 1);

			if(start != end){
				lazy[2*currPos].type = 2;
                lazy[2*currPos].value = lazy[currPos].value;
                lazy[2*currPos+1].type = 2;
                lazy[2*currPos+1].value = lazy[currPos].value; 
			}
		}
		lazy[currPos].value = 0;
		lazy[currPos].type = 0;
	}

	if(start > right || end < left){
        return 0;
    }

    if(start >= left && end <= right){
        return tree[currPos].sum_of_squares;
    }

    int mid = (start + end)/2;
    int ans1 = queryLazy(tree,lazy,start,mid,left, right,2*currPos);
    int ans2 = queryLazy(tree,lazy, mid+1,end,left, right, 2*currPos+1);

    int ans = ans1 + ans2;
    return ans;
}

int main(){
	int T;
	cin >> T;
	for(int j = 0; j < T; j++){
		int Q, n;
		cin >> n >> Q;
		Node_t* tree = new Node_t[4*n];
		Node_l* lazy = new Node_l[4*n];

		cout << "Case " << j+1 << ":\n";

        for(int i = 0; i < 4*n; i++){
            tree[i].sum_of_squares = 0;
            tree[i].sum = 0;
            lazy[i].value = 0;
            lazy[i].type = 0;
        }

		int* arr = new int[n];

		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}

		buildTree(arr, tree, 0, n-1, 1);

		int value, choice, left, right;

		while(Q--){
            cin >> choice;
            
            if(choice == 2){
                cin >> left >> right;
                cout << queryLazy(tree, lazy, 0, n-1, left-1, right-1, 1) << endl;
            }
            else if(choice == 0){
                cin >> left >> right >> value;
                updateLazy(tree, lazy, 0, n-1, left-1, right-1, 1, value, 2);
            }
            else if(choice == 1){
                cin >> left >> right >> value;
                updateLazy(tree, lazy, 0, n-1, left-1, right-1, 1, value, 1);
            }
        }
		delete[] arr;
		delete[] tree;
		delete[] lazy;
	}

}
