using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.CompilerServices;
using Newtonsoft.Json;

using System.Net.NetworkInformation;

namespace RandomTool
{
    public partial class Form1 : Form
    {
        private List<StudentItem> input = new List<StudentItem>();
        private List<StudentItem> result = new List<StudentItem>();
        private StudentItem curItem = null;
        private bool isRolling = false;
        private Random random = new Random();
        private string inFilePath = "";
        private string outFilePath = "";
        private readonly string stateFilePath = "state.json";

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            timerRoll.Interval = 80;
            LoadState();
            RefreshUI();
        }

        private void timerRoll_Tick(object sender, EventArgs e)
        {
            if (input.Count == 0)
            {
                timerRoll.Stop();
                isRolling = false;
                labelCurrent.Text = "输入列表为空";
                SaveState();
                return;
            }

            int index = random.Next(input.Count);
            curItem = input[index];
            labelCurrent.Text = $"{curItem.StudentID} : {curItem.Name}";
        }

        private void RefreshUI()
        {
            listBoxInput.Items.Clear();
            foreach (var item in input)
            {
                listBoxInput.Items.Add(item);
            }

            listBoxResult.Items.Clear();
            foreach (var item in result)
            {
                listBoxResult.Items.Add(item);
            }

            if (curItem != null)
            {
                labelCurrent.Text = $"{curItem.StudentID} : {curItem.Name}";
            }
            else
            {
                labelCurrent.Text = "点击GO抽取";
            }
        }

        private void ucBtnRead_BtnClick(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }
            inFilePath = openFileDialog.FileName;

            try
            {
                var lines = File.ReadAllLines(inFilePath);
                input.Clear();
                result.Clear();
                curItem = null;
                isRolling = false;
                timerRoll.Stop();

                foreach (var line in lines)
                {
                    if (string.IsNullOrWhiteSpace(line))
                    {
                        continue;
                    }

                    var parts = line.Split(new char[] { ',', '，', ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);

                    if (parts.Length >= 3)
                    {
                        input.Add(new StudentItem
                        {
                            StudentID = parts[0],
                            Name = parts[1]
                        });
                    }
                    else if (parts.Length == 2)
                    {
                        input.Add(new StudentItem
                        {
                            StudentID = parts[0],
                            Name = parts[1]
                        });
                    }
                }

                SaveState();
                RefreshUI();
                MessageBox.Show("读取成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show("读取失败：" + ex.Message);
            }
        }

        private void ucBtnGo_BtnClick(object sender, EventArgs e)
        {
            if (input.Count == 0)
            {
                MessageBox.Show("输入列表为空，请先读取文件");
                return;
            }

            if (isRolling)
            {
                return;
            }

            isRolling = true;
            timerRoll.Start();
            SaveState();
        }

        private void ucBtnStop_BtnClick(object sender, EventArgs e)
        {
            if (!isRolling)
            {
                MessageBox.Show("当前没有在抽取");
                return;
            }

            timerRoll.Stop();
            isRolling = false;

            if (curItem == null)
            {
                MessageBox.Show("当前没有可停止的条目");
                SaveState();
                return;
            }

            var target = input.FirstOrDefault(x =>
                x.StudentID == curItem.StudentID &&
                x.Name == curItem.Name);

            if (target != null)
            {
                input.Remove(target);
                result.Add(target);
            }

            SaveState();
            RefreshUI();
        }

        private void ucBtnShuffle_BtnClick(object sender, EventArgs e)
        {
            if (result.Count == 0)
            {
                result = input
                    .Select(x => new StudentItem
                    {
                        StudentID = x.StudentID,
                        Name = x.Name
                    })
                    .ToList();
            }

            result = result
                .OrderBy(x => random.Next())
                .ToList();

            SaveState();
            RefreshUI();
        }

        private void ucBtnWrite_BtnClick(object sender, EventArgs e)
        {
            if (result.Count == 0)
            {
                MessageBox.Show("结果列表为空");
                return;
            }

            SaveFileDialog sfd = new SaveFileDialog();

            if (sfd.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            outFilePath = sfd.FileName;

            try
            {
                var lines = result.Select(x => $"{x.StudentID},{x.Name}").ToArray();
                File.WriteAllLines(outFilePath, lines);
                SaveState();
                MessageBox.Show("写入成功");
            }
            catch (Exception ex)
            {
                MessageBox.Show("写入失败：" + ex.Message);
            }
        }

        private void SaveState()
        {
            try
            {
                State state = new State
                {
                    InputList = input,
                    ResultList = result,
                    CurItem = curItem,
                    IsRolling = isRolling,
                    InFilePath = inFilePath,
                    OutFilePath = outFilePath
                };

                string json = JsonConvert.SerializeObject(state, Formatting.Indented);
                File.WriteAllText(stateFilePath, json);
            }
            catch
            {
            }
        }

        private void LoadState()
        {
            try
            {
                if (!File.Exists(stateFilePath))
                {
                    return;
                }

                string json = File.ReadAllText(stateFilePath);
                State state = JsonConvert.DeserializeObject<State>(json);

                if (state == null)
                {
                    return;
                }

                input = state.InputList ?? new List<StudentItem>();
                result = state.ResultList ?? new List<StudentItem>();
                curItem = state.CurItem;
                isRolling = false;
                inFilePath = state.InFilePath ?? "";
                outFilePath = state.OutFilePath ?? "";

                timerRoll.Stop();
            }
            catch
            {
                input = new List<StudentItem>();
                result = new List<StudentItem>();
                curItem = null;
                isRolling = false;
            }
        }

        private void Form1_FoemClosing(Object sender, FormClosingEventArgs e)
        {
            SaveState();
        }
    }
}
