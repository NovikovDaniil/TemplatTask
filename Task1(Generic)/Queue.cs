using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1_Generic_
{
    class Queue<T>
    {
        private int maxSize;
        private T[] queue;
        private int start, end;
        private int count;

        public Queue(int _maxSize)
        {
            maxSize = _maxSize;
            queue = new T[maxSize];
            count = 0;
            start = 0;
            end = -1;
        }

        public Queue(Queue<T> other)
        {
            maxSize = other.maxSize;
            queue = new T[maxSize];
            other.queue.CopyTo(queue, 0);
            count = other.count;
            start = other.start;
            end = other.end;
        }

        public int Size => count;

        public bool IsEmpty() => (count == 0) ? true : false;

        public bool IsFull() => (count == maxSize) ? true : false;

        public void Push(T value)
        {
            if (IsFull()) throw new OutOfMemoryException("Queue is full!");
            else
            {
                end = (end + 1) % maxSize;
                queue[end] = value;
                ++count;
            }
        }

        public T Pop()
        {
            if (IsEmpty())
                throw new ArgumentOutOfRangeException("Queue is empty!");
            else
            {
                T tmp = queue[start];
                --count;
                start = (start + 1) % maxSize;
                return tmp;
            }
        }

        static public Queue<T> UnionQueues(Queue<T> first, Queue<T> second)
        {
            Queue<T> result = new Queue<T>(first.maxSize + second.maxSize);
            int resultCount = 0;
            int index = first.start;
            while (resultCount < first.count)
            {
                result.Push(first.queue[index]);
                ++resultCount;
                index = (index + 1) % first.maxSize;
            }
            index = second.start;
            resultCount = 0;
            while (resultCount < second.count)
            {
                result.Push(second.queue[index]);
                ++resultCount;
                index = (index + 1) % second.maxSize;
            }
            return result;
        }
    }
}
