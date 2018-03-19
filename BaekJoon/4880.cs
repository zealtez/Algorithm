using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cSharP4880NextNum
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                int[] value = new int[3];
                var NM = Console.ReadLine().Split().Select(e => int.Parse(e)).ToArray();
                for (int i = 0; i < 3; i++)
                    value[i] = NM[i];
                if (value[0] == value[1] && value[1] == value[2] && value[2] == 0)
                    return;
                else
                {
                    if(value[2] - value[1] == value[1] - value[0])
                    {
                        Console.WriteLine("AP {0}", value[2] + (value[2] - value[1]));
                        
                    }else{
                        Console.WriteLine("GP {0}", value[2] * (value[2] / value[1]));
                    }
                }
            }
        }
    }
}
