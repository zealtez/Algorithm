using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace cSharP_10874TestFromLee
{
    
    class Program
    {
        
        static void Main(string[] args)
        {
            int[,] stu = new int[101, 10];
            int N = Convert.ToInt32(Console.ReadLine());
            for(int i = 0; i<N; i++)
            {
                var NM = Console.ReadLine().Split().Select(e => int.Parse(e)).ToArray();
                for (var j = 0; j < 10; j++)
                {
                    stu[i, j] = NM[j];
                }
                
            }
            for(int i = 0; i<N; i++)
            {
                bool flag = false;
                for(int j = 0; j<5; j++)
                {
                    if (stu[i, j] == stu[i, j + 5] && stu[i, j] == (j + 1) % 6)
                        continue;
                    else
                        flag = true;
                }
                if (flag == false)
                    Console.WriteLine(i + 1);
                    
            }
        }
    }
}
