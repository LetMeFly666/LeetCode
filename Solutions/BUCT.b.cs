/*
 * @Author: LetMeFly
 * @Date: 2023-03-01 19:11:46
 * @LastEditors: LetMeFly
 * @LastEditTime: 2023-03-01 20:11:04
 */
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Threading;
using PengSW.NotifyPropertyChanged;
using PengSW.SignalHelper;
using TrackingCore.Sensor;
using static PengSW.RuntimeLog.RL;

namespace SensorSimulator
{
    class MainModel : NotifyPropertyChangedObject, ISignalable
    {
        public MainModel()
        {
            _Timer.Tick += OnTimer_Tick;
        }

        public event EventHandler SignalEnable;
        public event EventHandler SignalDisable;

        public ISensor[] Sensors { get; } = new ISensor[] 
        {
            new SensorFromFile(),
            new SensorFreeD("Shotoku D1", 29, 0xD1, 0x01, 5, 2, 0, 20, 23, 11, 14, 17),
            new SensorFreeD("Gension D1", 29, 0xD1, 0x01, 2, 5, 0, 20, 23, 11, 14, 17),
            new SensorFreeD("Seeder", 29, 0xD1, 0x00, 5, 2, 0, 20, 23, 11, 14, 17),
            new SensorFreeD("Shotoku A0", 15, 0xA0, 0x02, 5, 2, 0, 8, 11, 0, 0, 0),

        };

        public ISensor CurrentSensor { get => _CurrentSensor; set { SetValue(ref _CurrentSensor, value, nameof(CurrentSensor)); } }
        private ISensor _CurrentSensor;

        private void OnTimer_Tick(object sender, EventArgs e)

        {
            if (CurrentSensor == null) return;
            try
            {
                byte[] aFrame = CurrentSensor.GetFrame();
                if (aFrame == null) return;
                _UdpClient.Send(aFrame, aFrame.Length, TargetHost, Port);
                SignalEnable?.Invoke(this, EventArgs.Empty);
            }
            catch (Exception ex)
            {
                E(ex);
            }
        }

        public void Start()
        {
            _Timer.Interval = TimeSpan.FromMilliseconds(1000.0 / FPS);
            _Timer.Start();
            OnPropertiesChanged(nameof(CanStart), nameof(CanStop));
        }

        public bool CanStart => !_Timer.IsEnabled && (CurrentSensor?.IsValid ?? false);

        public void Stop()
        {
            _Timer.Stop();
            OnPropertiesChanged(nameof(CanStart), nameof(CanStop));
        }

        public bool CanStop => _Timer.IsEnabled;

        public string TargetHost { get => _TargetHost; set { SetValue(ref _TargetHost, value, nameof(TargetHost)); } }
        private string _TargetHost = "127.0.0.1";

        public int Port { get => _Port; set { SetValue(ref _Port, value, nameof(Port)); } }
        private int _Port = 20001;

        public int FPS { get => _FPS; set { SetValue(ref _FPS, value <= 0 ? 50 : value, nameof(FPS)); } }
        private int _FPS = 50;
        
        private readonly DispatcherTimer _Timer = new DispatcherTimer();
        private readonly UdpClient _UdpClient = new UdpClient();
    }
}