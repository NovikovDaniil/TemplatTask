using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2_Generic_
{
    class Program
    {
        static void Main(string[] args)
        {
            //BinaryTree<int> a = new BinaryTree<int>();
            //a.Add(10);
            //a.Add(5);
            //a.Add(12);
            //a.Add(4);
            //List<int> v1 = a.GetLeafList();
            //foreach (var item in v1)
            //    Console.Write(item + "  ");
            //Console.WriteLine(a);

            //if (a.Contains(5)) Console.WriteLine("Yes!!");
            //else Console.WriteLine("No!!");
            //List<int> v = a.Traversal();
            //foreach (var item in v)
            //    Console.Write(item + "  ");
            BinaryTree<string> a = new BinaryTree<string>();
            a.Add("hello");
            a.Add("ara");
            a.Add("xax");
            a.Add("zuzuz");
            a.Add("bumble");
            Console.WriteLine(a);
            a.Remove("xax");
            Console.WriteLine(a);
        }
    }
}
