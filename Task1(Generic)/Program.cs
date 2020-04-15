using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1_Generic_
{
    class Program
    {
        static void Main(string[] args)
        {
            Queue<int> a = new Queue<int>(5);
            a.Push(5);
            a.Push(10);
            a.Push(7);
            a.Push(1);
            a.Pop();

            Queue<int> b = new Queue<int>(4);
            b.Push(2);
            b.Push(5);
            b.Push(6);
            Queue<int> c = Queue<int>.UnionQueues(a, b);
        }
    }
}
