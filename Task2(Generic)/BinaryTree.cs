using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2_Generic_
{
    class BinaryTree<T> where T : IComparable<T>
    {
        class Node
        {
            public T data;
            public Node left;
            public Node right;
            public Node(T _data)
            {
                data = _data;
                left = null;
                right = null;
            }
        }
        Node root;

        public BinaryTree()
        {
            root = null;
        }
        public void Add(T data)
        {
            if (root == null)
                root = new Node(data);
            else Add(data, ref root);
        }

        private void Add(T data, ref Node root)
        {
            if (root == null)
                root = new Node(data);
            else if (data.CompareTo(root.data) < 0) Add(data, ref root.left);
            else if (data.CompareTo(root.data) > 0) Add(data, ref root.right);
            else throw new ArgumentException("This value is already in the tree!");
        }

        public void Remove(T data)
        {
            Remove(data, ref root);
        }

        private void Remove(T data, ref Node root)
        {
            if (root == null)
            {
                throw new ArgumentException("Item to delete was not found");
            }
            if (data.CompareTo(root.data) > 0) Remove(data, ref root.right);
            else if (data.CompareTo(root.data) < 0) Remove(data, ref root.left);
            else
            {
                Node temp = root;
                if (temp.right == null && temp.left == null)
                {
                    root = null;
                }
                else if (temp.right == null && temp.left != null)
                {
                    root = temp.left;
                }
                else if (temp.left == null && temp.right != null)
                {
                    root = temp.right;
                }
                else
                {
                    Node maxNode = temp.left;//to delete an item will look for the maximum number in the left subtree to replace
                    while (maxNode.right != null) maxNode = maxNode.right;
                    temp.data = maxNode.data;
                    Remove(maxNode.data, ref temp.left);
                }
            }
        }

        public bool Contains(T data)
        {
            return Contains(data, root);
        }

        private bool Contains(T data, Node root)
        {
            if (root == null) return false;
            else if (data.CompareTo(root.data) == 0) return true;
            else if (data.CompareTo(root.data) > 0) return Contains(data, root.right);
            else return Contains(data, root.left);
        }

        public List<T> GetLeafList()
        {
            List<T> leafList = new List<T>();
            void getLeaf(Node root)
            {
                if (root.left == null && root.right == null)
                    leafList.Add(root.data);
                else
                {
                    if (root.left != null) getLeaf(root.left);
                    if (root.right != null) getLeaf(root.right);
                }
            }
            getLeaf(root);
            return leafList;
        }

        public List<T> Traversal()
        {
            List<T> vertexes = new List<T>();
            void traversal(Node root)
            {
                if (root != null)
                {
                    traversal(root.left);
                    vertexes.Add(root.data);
                    traversal(root.right);
                }
            }
            traversal(root);
            return vertexes;
        }

        private string BinaryTreeAsString(Node node)
        {
            string leftStr = (node.left == null) ? "{}" : BinaryTreeAsString(node.left);
            string rightStr = (node.right == null) ? "{}" : BinaryTreeAsString(node.right);
            string result = "{" + (node.data).ToString() + ", " + leftStr + ", " + rightStr + "}";
            return result;
        }
        public override string ToString()
        {
            if (root == null) return "{}";
            else return BinaryTreeAsString(root);
        }
    }
}
