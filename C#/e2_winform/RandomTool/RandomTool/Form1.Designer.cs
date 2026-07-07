namespace RandomTool
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.listBoxInput = new System.Windows.Forms.ListBox();
            this.labelCurrent = new System.Windows.Forms.Label();
            this.listBoxResult = new System.Windows.Forms.ListBox();
            this.ucBtnRead = new HZH_Controls.Controls.UCBtnExt();
            this.ucBtnWrite = new HZH_Controls.Controls.UCBtnExt();
            this.ucBtnGo = new HZH_Controls.Controls.UCBtnExt();
            this.ucBtnStop = new HZH_Controls.Controls.UCBtnExt();
            this.ucBtnShuffle = new HZH_Controls.Controls.UCBtnExt();
            this.timerRoll = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // listBoxInput
            // 
            this.listBoxInput.FormattingEnabled = true;
            this.listBoxInput.ItemHeight = 24;
            this.listBoxInput.Location = new System.Drawing.Point(12, 12);
            this.listBoxInput.Name = "listBoxInput";
            this.listBoxInput.Size = new System.Drawing.Size(385, 676);
            this.listBoxInput.TabIndex = 0;
            // 
            // labelCurrent
            // 
            this.labelCurrent.AutoSize = true;
            this.labelCurrent.Location = new System.Drawing.Point(562, 237);
            this.labelCurrent.Name = "labelCurrent";
            this.labelCurrent.Size = new System.Drawing.Size(82, 24);
            this.labelCurrent.TabIndex = 1;
            this.labelCurrent.Text = "label1";
            // 
            // listBoxResult
            // 
            this.listBoxResult.FormattingEnabled = true;
            this.listBoxResult.ItemHeight = 24;
            this.listBoxResult.Location = new System.Drawing.Point(833, 12);
            this.listBoxResult.Name = "listBoxResult";
            this.listBoxResult.Size = new System.Drawing.Size(402, 676);
            this.listBoxResult.TabIndex = 2;
            // 
            // ucBtnRead
            // 
            this.ucBtnRead.BackColor = System.Drawing.Color.Transparent;
            this.ucBtnRead.BtnBackColor = System.Drawing.Color.White;
            this.ucBtnRead.BtnFont = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ucBtnRead.BtnForeColor = System.Drawing.Color.White;
            this.ucBtnRead.BtnText = "READ";
            this.ucBtnRead.ConerRadius = 5;
            this.ucBtnRead.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ucBtnRead.EnabledMouseEffect = false;
            this.ucBtnRead.FillColor = System.Drawing.Color.DarkTurquoise;
            this.ucBtnRead.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.ucBtnRead.IsRadius = true;
            this.ucBtnRead.IsShowRect = true;
            this.ucBtnRead.IsShowTips = false;
            this.ucBtnRead.Location = new System.Drawing.Point(412, 543);
            this.ucBtnRead.Margin = new System.Windows.Forms.Padding(0);
            this.ucBtnRead.Name = "ucBtnRead";
            this.ucBtnRead.RectColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(58)))));
            this.ucBtnRead.RectWidth = 1;
            this.ucBtnRead.Size = new System.Drawing.Size(184, 60);
            this.ucBtnRead.TabIndex = 3;
            this.ucBtnRead.TabStop = false;
            this.ucBtnRead.TipsColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(30)))), ((int)(((byte)(99)))));
            this.ucBtnRead.TipsText = "";
            this.ucBtnRead.BtnClick += new System.EventHandler(this.ucBtnRead_BtnClick);
            // 
            // ucBtnWrite
            // 
            this.ucBtnWrite.BackColor = System.Drawing.Color.Transparent;
            this.ucBtnWrite.BtnBackColor = System.Drawing.Color.White;
            this.ucBtnWrite.BtnFont = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ucBtnWrite.BtnForeColor = System.Drawing.Color.White;
            this.ucBtnWrite.BtnText = "WRITE";
            this.ucBtnWrite.ConerRadius = 5;
            this.ucBtnWrite.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ucBtnWrite.EnabledMouseEffect = false;
            this.ucBtnWrite.FillColor = System.Drawing.Color.Teal;
            this.ucBtnWrite.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.ucBtnWrite.IsRadius = true;
            this.ucBtnWrite.IsShowRect = true;
            this.ucBtnWrite.IsShowTips = false;
            this.ucBtnWrite.Location = new System.Drawing.Point(622, 543);
            this.ucBtnWrite.Margin = new System.Windows.Forms.Padding(0);
            this.ucBtnWrite.Name = "ucBtnWrite";
            this.ucBtnWrite.RectColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(58)))));
            this.ucBtnWrite.RectWidth = 1;
            this.ucBtnWrite.Size = new System.Drawing.Size(184, 60);
            this.ucBtnWrite.TabIndex = 4;
            this.ucBtnWrite.TabStop = false;
            this.ucBtnWrite.TipsColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(30)))), ((int)(((byte)(99)))));
            this.ucBtnWrite.TipsText = "";
            this.ucBtnWrite.BtnClick += new System.EventHandler(this.ucBtnWrite_BtnClick);
            // 
            // ucBtnGo
            // 
            this.ucBtnGo.BackColor = System.Drawing.Color.Transparent;
            this.ucBtnGo.BtnBackColor = System.Drawing.Color.White;
            this.ucBtnGo.BtnFont = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ucBtnGo.BtnForeColor = System.Drawing.Color.White;
            this.ucBtnGo.BtnText = "GO";
            this.ucBtnGo.ConerRadius = 5;
            this.ucBtnGo.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ucBtnGo.EnabledMouseEffect = false;
            this.ucBtnGo.FillColor = System.Drawing.Color.Lime;
            this.ucBtnGo.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.ucBtnGo.IsRadius = true;
            this.ucBtnGo.IsShowRect = true;
            this.ucBtnGo.IsShowTips = false;
            this.ucBtnGo.Location = new System.Drawing.Point(412, 619);
            this.ucBtnGo.Margin = new System.Windows.Forms.Padding(0);
            this.ucBtnGo.Name = "ucBtnGo";
            this.ucBtnGo.RectColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(58)))));
            this.ucBtnGo.RectWidth = 1;
            this.ucBtnGo.Size = new System.Drawing.Size(112, 60);
            this.ucBtnGo.TabIndex = 5;
            this.ucBtnGo.TabStop = false;
            this.ucBtnGo.TipsColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(30)))), ((int)(((byte)(99)))));
            this.ucBtnGo.TipsText = "";
            this.ucBtnGo.BtnClick += new System.EventHandler(this.ucBtnGo_BtnClick);
            // 
            // ucBtnStop
            // 
            this.ucBtnStop.BackColor = System.Drawing.Color.White;
            this.ucBtnStop.BtnBackColor = System.Drawing.Color.White;
            this.ucBtnStop.BtnFont = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ucBtnStop.BtnForeColor = System.Drawing.Color.White;
            this.ucBtnStop.BtnText = "STOP";
            this.ucBtnStop.ConerRadius = 5;
            this.ucBtnStop.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ucBtnStop.EnabledMouseEffect = false;
            this.ucBtnStop.FillColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(59)))));
            this.ucBtnStop.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.ucBtnStop.IsRadius = true;
            this.ucBtnStop.IsShowRect = true;
            this.ucBtnStop.IsShowTips = false;
            this.ucBtnStop.Location = new System.Drawing.Point(533, 619);
            this.ucBtnStop.Margin = new System.Windows.Forms.Padding(0);
            this.ucBtnStop.Name = "ucBtnStop";
            this.ucBtnStop.RectColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(58)))));
            this.ucBtnStop.RectWidth = 1;
            this.ucBtnStop.Size = new System.Drawing.Size(111, 60);
            this.ucBtnStop.TabIndex = 6;
            this.ucBtnStop.TabStop = false;
            this.ucBtnStop.TipsColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(30)))), ((int)(((byte)(99)))));
            this.ucBtnStop.TipsText = "";
            this.ucBtnStop.BtnClick += new System.EventHandler(this.ucBtnStop_BtnClick);
            // 
            // ucBtnShuffle
            // 
            this.ucBtnShuffle.BackColor = System.Drawing.Color.White;
            this.ucBtnShuffle.BtnBackColor = System.Drawing.Color.White;
            this.ucBtnShuffle.BtnFont = new System.Drawing.Font("微软雅黑", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ucBtnShuffle.BtnForeColor = System.Drawing.Color.White;
            this.ucBtnShuffle.BtnText = "SHUFFLE";
            this.ucBtnShuffle.ConerRadius = 5;
            this.ucBtnShuffle.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ucBtnShuffle.EnabledMouseEffect = false;
            this.ucBtnShuffle.FillColor = System.Drawing.Color.Yellow;
            this.ucBtnShuffle.Font = new System.Drawing.Font("微软雅黑", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Pixel);
            this.ucBtnShuffle.IsRadius = true;
            this.ucBtnShuffle.IsShowRect = true;
            this.ucBtnShuffle.IsShowTips = false;
            this.ucBtnShuffle.Location = new System.Drawing.Point(652, 619);
            this.ucBtnShuffle.Margin = new System.Windows.Forms.Padding(0);
            this.ucBtnShuffle.Name = "ucBtnShuffle";
            this.ucBtnShuffle.RectColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(77)))), ((int)(((byte)(58)))));
            this.ucBtnShuffle.RectWidth = 1;
            this.ucBtnShuffle.Size = new System.Drawing.Size(154, 60);
            this.ucBtnShuffle.TabIndex = 6;
            this.ucBtnShuffle.TabStop = false;
            this.ucBtnShuffle.TipsColor = System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(30)))), ((int)(((byte)(99)))));
            this.ucBtnShuffle.TipsText = "";
            this.ucBtnShuffle.BtnClick += new System.EventHandler(this.ucBtnShuffle_BtnClick);
            // 
            // timerRoll
            // 
            this.timerRoll.Tick += new System.EventHandler(this.timerRoll_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1247, 702);
            this.Controls.Add(this.ucBtnShuffle);
            this.Controls.Add(this.ucBtnStop);
            this.Controls.Add(this.ucBtnGo);
            this.Controls.Add(this.ucBtnWrite);
            this.Controls.Add(this.ucBtnRead);
            this.Controls.Add(this.listBoxResult);
            this.Controls.Add(this.labelCurrent);
            this.Controls.Add(this.listBoxInput);
            this.Name = "Form1";
            this.Text = "随机工具";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxInput;
        private System.Windows.Forms.Label labelCurrent;
        private System.Windows.Forms.ListBox listBoxResult;
        private HZH_Controls.Controls.UCBtnExt ucBtnRead;
        private HZH_Controls.Controls.UCBtnExt ucBtnWrite;
        private HZH_Controls.Controls.UCBtnExt ucBtnGo;
        private HZH_Controls.Controls.UCBtnExt ucBtnStop;
        private HZH_Controls.Controls.UCBtnExt ucBtnShuffle;
        private System.Windows.Forms.Timer timerRoll;
    }
}

