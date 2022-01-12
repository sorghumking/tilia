object SynonymInfoForm: TSynonymInfoForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Synonymy Details'
  ClientHeight = 460
  ClientWidth = 393
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object cxGroupBox1: TcxGroupBox
    Left = 0
    Top = 0
    Align = alClient
    Alignment = alTopCenter
    Ctl3D = True
    PanelStyle.Active = True
    PanelStyle.OfficeBackgroundKind = pobkGradient
    ParentBackground = False
    ParentColor = False
    ParentCtl3D = False
    ParentFont = False
    Style.BorderStyle = ebsNone
    Style.Color = 15984090
    Style.Edges = []
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -11
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.LookAndFeel.Kind = lfOffice11
    Style.LookAndFeel.NativeStyle = False
    Style.Shadow = False
    Style.TransparentBorder = True
    Style.IsFontAssigned = True
    StyleDisabled.LookAndFeel.Kind = lfOffice11
    StyleDisabled.LookAndFeel.NativeStyle = False
    StyleFocused.LookAndFeel.Kind = lfOffice11
    StyleFocused.LookAndFeel.NativeStyle = False
    StyleHot.LookAndFeel.Kind = lfOffice11
    StyleHot.LookAndFeel.NativeStyle = False
    TabOrder = 0
    Height = 441
    Width = 393
    object cxMemo1: TcxMemo
      Left = 8
      Top = 112
      Properties.HideSelection = False
      Properties.ReadOnly = True
      Properties.ScrollBars = ssVertical
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 5
      Height = 65
      Width = 377
    end
    object cxMemo2: TcxMemo
      Left = 8
      Top = 200
      Properties.HideSelection = False
      Properties.ReadOnly = True
      Properties.ScrollBars = ssVertical
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 6
      Height = 65
      Width = 377
    end
    object cxTextEdit1: TcxTextEdit
      Left = 8
      Top = 376
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 8
      Width = 251
    end
    object cxTextEdit2: TcxTextEdit
      Left = 270
      Top = 376
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 9
      Width = 115
    end
    object cxButton1: TcxButton
      Left = 162
      Top = 408
      Width = 75
      Height = 25
      Caption = '&Close'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 11
      TabOrder = 0
    end
    object cxMemo3: TcxMemo
      Left = 8
      Top = 288
      Properties.HideSelection = False
      Properties.ReadOnly = True
      Properties.ScrollBars = ssVertical
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 7
      Height = 65
      Width = 377
    end
    object cxTextEdit3: TcxTextEdit
      Left = 8
      Top = 24
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 1
      Width = 185
    end
    object cxTextEdit4: TcxTextEdit
      Left = 200
      Top = 24
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 2
      Width = 185
    end
    object cxTextEdit5: TcxTextEdit
      Left = 8
      Top = 68
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 3
      Width = 185
    end
    object cxTextEdit6: TcxTextEdit
      Left = 200
      Top = 68
      Properties.ReadOnly = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 4
      Width = 185
    end
    object cxLabel1: TcxLabel
      Left = 8
      Top = 359
      Caption = 'Validated By:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel2: TcxLabel
      Left = 270
      Top = 359
      Caption = 'Date:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel4: TcxLabel
      Left = 8
      Top = 7
      Caption = 'Depreciated Name:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel5: TcxLabel
      Left = 200
      Top = 7
      Caption = 'Author:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel6: TcxLabel
      Left = 8
      Top = 51
      Caption = 'Valid Name:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel7: TcxLabel
      Left = 200
      Top = 51
      Caption = 'Author:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel8: TcxLabel
      Left = 8
      Top = 95
      Caption = 'Reference:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel9: TcxLabel
      Left = 8
      Top = 183
      Caption = 'Synonymy Notes:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
    object cxLabel10: TcxLabel
      Left = 8
      Top = 271
      Caption = 'Notes for Valid Name:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      Transparent = True
    end
  end
  object cxGroupBox2: TcxGroupBox
    Left = 60
    Top = 68
    Ctl3D = True
    PanelStyle.Active = True
    ParentBackground = False
    ParentColor = False
    ParentCtl3D = False
    Style.BorderColor = clNavy
    Style.BorderStyle = ebsSingle
    Style.Color = 15984090
    Style.Edges = [bLeft, bTop, bRight, bBottom]
    Style.LookAndFeel.Kind = lfFlat
    Style.Shadow = True
    Style.TransparentBorder = True
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 1
    Visible = False
    Height = 294
    Width = 273
    object cxMemo4: TcxMemo
      Left = 12
      Top = 15
      Lines.Strings = (
        'Name not found as a depreciated synonym in '
        'Neotoma! If the name has non-Latin parts (e.g. '
        #39'cf.'#39', '#39'-type'#39', '#39'undiff'#39#39', '#39'?'#39'), try searching for just '
        'the Latin part.')
      ParentFont = False
      Properties.ReadOnly = True
      Style.BorderStyle = ebsNone
      Style.Color = 15984090
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
      StyleDisabled.Color = 15984090
      StyleDisabled.TextColor = clNavy
      TabOrder = 0
      Height = 60
      Width = 244
    end
    object cxTextEdit7: TcxTextEdit
      Left = 12
      Top = 103
      Properties.OnChange = cxTextEdit7PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 1
      OnKeyPress = cxTextEdit7KeyPress
      Width = 244
    end
    object cxLabel3: TcxLabel
      Left = 12
      Top = 86
      Caption = 'Search term (use '#39'%'#39' for wildcard)'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxButton2: TcxButton
      Left = 220
      Top = 81
      Width = 36
      Height = 21
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.Glyph.Data = {
        F6000000424DF600000000000000760000002800000010000000100000000100
        04000000000080000000CE0E0000C40E00001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777777777777777777700000777770000070F000777770F00070F000777770F
        0007000000070000000700F000000F00000700F000700F00000700F000700F00
        00077000000000000077770F00070F0007777700000700000777777000777000
        77777770F07770F0777777700077700077777777777777777777}
      TabOrder = 3
      OnClick = cxButton2Click
    end
    object cxLabel11: TcxLabel
      Left = 12
      Top = 130
      Caption = 'Select a name:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxButton3: TcxButton
      Left = 58
      Top = 255
      Width = 75
      Height = 25
      Caption = '&Show Details'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      TabOrder = 5
      OnClick = cxButton3Click
    end
    object cxButton4: TcxButton
      Left = 139
      Top = 255
      Width = 75
      Height = 25
      Caption = '&Cancel'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 6
      OnClick = cxButton4Click
    end
    object cxListBox1: TcxListBox
      Left = 12
      Top = 148
      Width = 245
      Height = 97
      ItemHeight = 13
      Sorted = True
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 7
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 441
    Width = 393
    Height = 19
    Color = 14854529
    Panels = <>
  end
  object TcpClient1: TTcpClient
    Left = 344
    Top = 408
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 304
    Top = 408
  end
end
