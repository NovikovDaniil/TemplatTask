using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task3_Generic_
{
    class AVLTree<T> where T : IComparable<T>
    {
        class Node
        {
            public T data;
            public Node left;
            public Node right;
            public int height;
            public Node(T _data)
            {
                data = _data;
                left = null;
                right = null;
                height = 0;
            }
        }
        Node root;

        private void MakeNewHeight(ref Node root)
        {
            int heightLeft, heightRight;
            heightLeft = (root.left != null) ? (root.left).height : 0;
            heightRight = (root.right != null) ? (root.right).height : 0;
            if (heightLeft > heightRight)
                root.height = heightLeft + 1;
            else
                root.height = heightRight + 1;
        }

        private int GetBalance(Node root)
        {
            int heightLeft, heightRight;
            heightLeft = (root.left != null) ? (root.left).height : 0;
            heightRight = (root.right != null) ? (root.right).height : 0;
            return heightRight - heightLeft;
        }

        private void TurnL(ref Node root)
        {
            Node q = root.left;
            root.left = q.right;
            q.right = root;
            MakeNewHeight(ref root);
            MakeNewHeight(ref q);
            root = q;
        }

        private void TurnR(ref Node root)
        {
            Node q = root.right;
            root.right = q.left;
            q.left = root;
            MakeNewHeight(ref root);
            MakeNewHeight(ref q);
            root = q;
        }


        private void Balance(ref Node root)//function to maintain features of  avl tree
        {
            MakeNewHeight(ref root);
            if (GetBalance(root) > 1) // if the right subtree is higher than the permissible level
            {
                if (GetBalance(root.right) < 0) TurnL(ref root.right);// if the right child has a height of the left subtree greater than the height of the right subtree, then perform a big left turn
                TurnR(ref root);
            }
            else if (GetBalance(root) < -1)// if the left subtree is higher than the permissible level
            {
                if (GetBalance(root.left) > 0) TurnR(ref root.left);//do big right turn
                TurnL(ref root);
            }
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
            {
                root = new Node(data);
            }
            else if (data.CompareTo(root.data) < 0) Add(data, ref root.left);
            else if (data.CompareTo(root.data) > 0) Add(data, ref root.right);
            else throw new ArgumentException("This value is already in the tree!");
            Balance(ref root);
        }

        private Node FindMin(Node root)
        {
            if (root.left == null) return root;
            else return FindMin(root.left);
        }
        private Node RemoveMin(Node root)
        {
            if (root.left == null) return root.right;
            root.left = RemoveMin(root.left);
            Balance(ref root);
            return root;
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
                Node left = root.left;
                Node right = root.right;
                if (right == null)
                {
                    root = left;
                    return;
                }
                else
                {
                    Node min = FindMin(right);// look for a minimum in the right subtree of the deleted node to put this minimum in place of the deleted node
                    min.right = RemoveMin(right);
                    min.left = left;
                    root = min;
                    Balance(ref root);
                }
            }
            Balance(ref root);
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
