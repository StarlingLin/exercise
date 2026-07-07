using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomTool
{
    internal class State
    {
        public List<StudentItem> InputList {  get; set; } = new List<StudentItem>();
        public List<StudentItem> ResultList { get; set; } = new List<StudentItem>();
        public StudentItem CurItem { get; set; }
        public bool IsRolling { get; set; }
        public string InFilePath { get; set; }
        public string OutFilePath { get; set; }
    }
}
