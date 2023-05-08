#include <iostream>
using namespace std;
template<typename type>
class node
{
public:
	type data;
	node <type> * right;
	node <type> * left;
	node() {
		right = NULL;
		left = NULL;
	}
	node(type _data) {
		data = _data;
		right = NULL;
		left = NULL;
	}
};
template<typename type>
class avl_tree {
public:
	node <type> * root;

	int height(node <type> * _root) {
		if (_root)
			return 1 + max(height(_root->left), height(_root->right));
		return 0;
	}

	int balance_factor(node <type> * _root) {
		return height(_root->right) - height(_root->left);
	}

	node <type> * insert(node <type> * _now, type _data) {
		if (!_now)
			_now = new node <type>(_data);
		else if (_data < _now->data) {
			_now->left = insert(_now->left, _data);
			_now = balance(_now);
		}
		else if (_data > _now->data) {
			_now->right = insert(_now->right, _data);
			_now = balance(_now);
		}
		return _now;
	}

	node <type> * left_left(node <type> * _parent) {
		node <type> * _temp = _parent->left;
		_parent->left = _temp->right;
		_temp->right = _parent;
		return _temp;
	}

	node <type> * right_right(node <type> * _parent) {
		node <type> * _temp = _parent->right;
		_parent->right = _temp->left;
		_temp->left = _parent;
		return _temp;
	}

	node <type> * right_left(node <type> * _parent) {
		node <type> * _pr = _parent->right;
		node <type> * _temp = _pr->left;
		_parent->right = _temp->left;
		_temp->left = _parent;
		_pr->left = _temp->right;
		_temp->right = _pr;
		return _temp;
	}

	node <type> * left_right(node <type> * _parent) {
		node <type> * _pl = _parent->left;
		node <type> * _temp = _pl->right;
		_parent->left = _temp->right;
		_pl->right = _temp->left;
		_temp->right = _parent;
		_temp->left = _pl;
		return _temp;
	}

	node <type> * balance(node <type> * _root) {
		int _bf = this->balance_factor(_root);

		if (_bf > 1) {
			if (this->balance_factor(_root->right) > 0)
				_root = this->right_right(_root);
			else
				_root = this->right_left(_root);
		}
		else if (_bf < -1) {
			if (this->balance_factor(_root->left) > 0)
				_root = this->left_right(_root);
			else
				_root = this->left_left(_root);
		}
		return _root;
	}

	avl_tree() {
		root = NULL;
	}

	void insert(type _data) {
		root = this->insert(root, _data);
	}

	node <type> * find(type _target) {
		node <type> * _current = root;
		while (_current) {
			if (_current->data == _target)
				return _current;
			_current = _target > _current->data ? _current->right : _current->left;
		}
		return NULL;
	}
};