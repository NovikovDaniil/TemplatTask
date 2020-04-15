using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task3_Generic_
{
    class Program
    {
        static void Main(string[] args)
        {
            AVLTree<int> a = new AVLTree<int>();
            a.Add(10);
            a.Add(20);
            a.Add(30);
            a.Add(40);
            a.Add(50);
            Console.WriteLine(a);
            List<int> b = a.GetLeafList();
            foreach (var item in b)
                Console.Write(item + "  ");
            Console.WriteLine();
            List<int> b1 = a.Traversal();
            foreach (var item in b1)
                Console.Write(item + "  ");
            //Console.WriteLine(a);
            //a.Remove(40);
            //Console.WriteLine(a);
            //a.Remove(10);
            //Console.WriteLine(a);
            //a.Remove(30);
            //Console.WriteLine(a);
            //a.Remove(50);
            //Console.WriteLine(a);
            //a.Remove(20);
        }
    }
}
