object XaxesForm: TXaxesForm
  Left = 1277
  Top = 142
  HelpContext = 26
  BorderIcons = [biSystemMenu, biHelp]
  BorderStyle = bsDialog
  Caption = 'X-axes'
  ClientHeight = 412
  ClientWidth = 504
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnHelp = FormHelp
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 56
    Width = 473
    Height = 305
    ActivePage = TabSheet1
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    TabWidth = 70
    object TabSheet1: TTabSheet
      HelpContext = 39
      Caption = '&Axis'
      ExplicitLeft = 0
      ExplicitTop = 25
      ExplicitWidth = 0
      ExplicitHeight = 276
      object Label1: TLabel
        Left = 16
        Top = 144
        Width = 54
        Height = 13
        Caption = 'Line Width:'
        FocusControl = LineWidthComboBox1
      end
      object Label2: TLabel
        Left = 112
        Top = 144
        Width = 52
        Height = 13
        Caption = 'Axis Color:'
      end
      object GroupBox1: TGroupBox
        Left = 224
        Top = 20
        Width = 105
        Height = 85
        HelpContext = 28
        Caption = 'Minimum Axis Limit'
        TabOrder = 0
        OnExit = GroupBox1Exit
        object Edit3: TEdit
          Left = 8
          Top = 52
          Width = 81
          Height = 21
          Hint = 'Minimum axis limit if Automatic is not checked'
          HelpContext = 28
          Color = clBtnFace
          Enabled = False
          TabOrder = 0
          OnChange = Edit3Change
        end
        object CheckBox1: TCheckBox
          Left = 8
          Top = 24
          Width = 65
          Height = 17
          Hint = 'Check to automatically determine the minimum axis limit'
          HelpContext = 28
          BiDiMode = bdLeftToRight
          Caption = 'Automatic'
          Enabled = False
          ParentBiDiMode = False
          TabOrder = 1
          OnClick = CheckBox1Click
        end
      end
      object GroupBox2: TGroupBox
        Left = 16
        Top = 200
        Width = 437
        Height = 57
        HelpContext = 1493
        Caption = 'Axis Label'
        TabOrder = 1
        object Edit5: TEdit
          Left = 8
          Top = 24
          Width = 400
          Height = 21
          Hint = 'Axis label'
          HelpContext = 31
          Enabled = False
          TabOrder = 0
          OnChange = Edit5Change
          OnExit = Edit5Exit
        end
        object BitBtn2: TBitBtn
          Left = 407
          Top = 24
          Width = 21
          Height = 21
          Hint = 'Axis label font'
          HelpContext = 20
          DoubleBuffered = True
          Enabled = False
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            04000000000080000000CE0E0000D80E00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
            8888888888888888888888884444488844448888884488888448888888844888
            8448888888884444444888888888844884488088808888448448807870888884
            4448870007888888444888080888888884488808088888888888887078888888
            8888888088888888888888888888888888888888888888888888}
          ParentDoubleBuffered = False
          TabOrder = 1
          OnClick = BitBtn2Click
        end
      end
      object GroupBox3: TGroupBox
        Left = 340
        Top = 20
        Width = 113
        Height = 85
        HelpContext = 29
        Caption = 'Maximum Axis Limit'
        TabOrder = 2
        OnExit = GroupBox3Exit
        object CheckBox2: TCheckBox
          Left = 8
          Top = 24
          Width = 97
          Height = 17
          Hint = 'Check to automatically determine the maximum axis limit'
          HelpContext = 29
          Caption = 'Automatic'
          Enabled = False
          TabOrder = 0
          OnClick = CheckBox2Click
        end
        object Edit4: TEdit
          Left = 8
          Top = 52
          Width = 81
          Height = 21
          Hint = 'Maximum axis limit if Automatic is not checked'
          HelpContext = 29
          Color = clBtnFace
          Enabled = False
          TabOrder = 1
          OnChange = Edit4Change
        end
      end
      object LineWidthComboBox1: TComboBox
        Left = 16
        Top = 160
        Width = 81
        Height = 21
        Hint = 'Axis line width'
        HelpContext = 6
        Enabled = False
        TabOrder = 3
        OnChange = LineWidthComboBox1Change
      end
      object RadioGroup1: TRadioGroup
        Left = 16
        Top = 20
        Width = 196
        Height = 109
        Hint = 'Method for determining the X-axis length'
        HelpContext = 27
        Caption = 'Axis Length'
        Enabled = False
        Items.Strings = (
          'Automatic'
          'Fixed Width'
          'Scale Factor')
        TabOrder = 4
        OnClick = RadioGroup1Click
        OnExit = RadioGroup1Exit
      end
      object Edit1: TEdit
        Left = 120
        Top = 68
        Width = 81
        Height = 21
        Hint = 'Fixed width'
        HelpContext = 27
        Color = clBtnFace
        Enabled = False
        TabOrder = 5
        OnExit = Edit1Exit
      end
      object Edit2: TEdit
        Left = 120
        Top = 98
        Width = 81
        Height = 21
        Hint = 'Scale factor'
        HelpContext = 27
        Color = clBtnFace
        Enabled = False
        TabOrder = 6
        OnExit = Edit2Exit
      end
      object ColorBox2: TColorBox
        Left = 112
        Top = 160
        Width = 121
        Height = 22
        Hint = 'Axis color'
        HelpContext = 7
        Style = [cbStandardColors, cbExtendedColors, cbCustomColor, cbPrettyNames]
        Enabled = False
        TabOrder = 7
        OnChange = ColorBox2Change
      end
      object LabeledEdit4: TLabeledEdit
        Left = 248
        Top = 160
        Width = 97
        Height = 21
        Hint = 'Space before the next graph in virtual units'
        HelpContext = 30
        EditLabel.Width = 77
        EditLabel.Height = 26
        EditLabel.HelpContext = 1496
        EditLabel.BiDiMode = bdLeftToRight
        EditLabel.Caption = 'Space Between Graphs:'
        EditLabel.ParentBiDiMode = False
        EditLabel.WordWrap = True
        TabOrder = 8
        OnChange = LabeledEdit4Change
        OnExit = LabeledEdit4Exit
      end
    end
    object TabSheet2: TTabSheet
      HelpContext = 40
      Caption = 'Tic &Marks'
      ImageIndex = 1
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox4: TGroupBox
        Left = 24
        Top = 8
        Width = 153
        Height = 129
        Hint = 'Step size between tic marks'
        HelpContext = 32
        Caption = 'Step Size'
        TabOrder = 0
        OnExit = GroupBox4Exit
        object CheckBox3: TCheckBox
          Left = 56
          Top = 16
          Width = 67
          Height = 17
          Hint = 'Check to automatically determine step size'
          HelpContext = 32
          Caption = 'Automatic'
          Enabled = False
          TabOrder = 0
          OnClick = CheckBox3Click
        end
        object LabeledEdit1: TLabeledEdit
          Left = 56
          Top = 40
          Width = 89
          Height = 21
          Hint = 'Step size between minor tic marks if Automatic is not checked'
          HelpContext = 32
          Color = clBtnFace
          EditLabel.Width = 30
          EditLabel.Height = 13
          EditLabel.Caption = 'Minor:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 1
          OnChange = LabeledEdit1Change
        end
        object LabeledEdit2: TLabeledEdit
          Left = 56
          Top = 70
          Width = 89
          Height = 21
          Hint = 'Step size between major tic marks if Automatic is not checked'
          HelpContext = 32
          Color = clBtnFace
          EditLabel.Width = 31
          EditLabel.Height = 13
          EditLabel.Caption = 'Major:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 2
          OnChange = LabeledEdit2Change
        end
        object LabeledEdit3: TLabeledEdit
          Left = 56
          Top = 100
          Width = 89
          Height = 21
          Hint = 'Step size between labeled tic marks if Automatic is not checked'
          HelpContext = 32
          Color = clBtnFace
          EditLabel.Width = 41
          EditLabel.Height = 13
          EditLabel.Caption = 'Labeled:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 3
          OnChange = LabeledEdit3Change
        end
      end
      object GroupBox5: TGroupBox
        Left = 200
        Top = 8
        Width = 242
        Height = 165
        Hint = 'Options for tic mark labels'
        HelpContext = 1499
        Caption = 'Tic Mark Labels'
        TabOrder = 1
        OnExit = GroupBox5Exit
        object CheckBox4: TCheckBox
          Left = 144
          Top = 140
          Width = 81
          Height = 17
          Hint = 'Check to label the X-axis origin'
          HelpContext = 36
          Caption = 'Label Origin'
          Enabled = False
          TabOrder = 0
          OnClick = CheckBox4Click
        end
        object LabeledEdit8: TLabeledEdit
          Left = 144
          Top = 16
          Width = 89
          Height = 21
          Hint = 'Distance from end of tic mark to the label'
          HelpContext = 33
          EditLabel.Width = 114
          EditLabel.Height = 13
          EditLabel.Caption = 'Distance From Tic Mark:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 1
          OnChange = LabeledEdit8Change
        end
        object LabeledEdit9: TLabeledEdit
          Left = 144
          Top = 46
          Width = 89
          Height = 21
          Hint = 'Factor by which the tic mark label is divided'
          HelpContext = 34
          EditLabel.Width = 48
          EditLabel.Height = 13
          EditLabel.Caption = 'Divide by:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 2
          OnChange = LabeledEdit9Change
        end
        object LabeledEdit10: TLabeledEdit
          Left = 144
          Top = 76
          Width = 89
          Height = 21
          Hint = 'Number of decimal points in the tic mark label'
          HelpContext = 35
          EditLabel.Width = 125
          EditLabel.Height = 13
          EditLabel.Caption = 'Number of Decimal Points:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 3
          OnChange = LabeledEdit10Change
        end
        object BitBtn3: TBitBtn
          Left = 144
          Top = 106
          Width = 89
          Height = 25
          Hint = 'Tic mark label font'
          HelpContext = 20
          Caption = 'Font'
          DoubleBuffered = True
          Enabled = False
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            04000000000080000000CE0E0000D80E00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
            8888888888888888888888884444488844448888884488888448888888844888
            8448888888884444444888888888844884488088808888448448807870888884
            4448870007888888444888080888888884488808088888888888887078888888
            8888888088888888888888888888888888888888888888888888}
          ParentDoubleBuffered = False
          TabOrder = 4
          OnClick = BitBtn3Click
        end
      end
      object GroupBox6: TGroupBox
        Left = 24
        Top = 150
        Width = 153
        Height = 113
        Hint = 'Tic mark lengths in virtual units'
        HelpContext = 37
        Caption = 'Lengths'
        TabOrder = 2
        OnExit = GroupBox6Exit
        object LabeledEdit5: TLabeledEdit
          Left = 56
          Top = 24
          Width = 89
          Height = 21
          Hint = 'Lengths of minor tic marks on bottom axis in virtual units'
          HelpContext = 37
          EditLabel.Width = 30
          EditLabel.Height = 13
          EditLabel.Caption = 'Minor:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 0
          OnChange = LabeledEdit5Change
        end
        object LabeledEdit6: TLabeledEdit
          Left = 56
          Top = 54
          Width = 89
          Height = 21
          Hint = 'Lengths of major tic marks on bottom axis in virtual units'
          HelpContext = 37
          EditLabel.Width = 31
          EditLabel.Height = 13
          EditLabel.Caption = 'Major:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 1
          OnChange = LabeledEdit6Change
        end
        object LabeledEdit7: TLabeledEdit
          Left = 56
          Top = 84
          Width = 89
          Height = 21
          Hint = 'Lengths of tic marks on top axis in virtual units'
          HelpContext = 37
          EditLabel.Width = 22
          EditLabel.Height = 13
          EditLabel.Caption = 'Top:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 2
          OnChange = LabeledEdit7Change
        end
      end
      object Panel2: TPanel
        Left = 200
        Top = 180
        Width = 241
        Height = 90
        Hint = 'Grid lines'
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 3
        object Label14: TLabel
          Left = 121
          Top = 6
          Width = 72
          Height = 13
          Caption = 'Grid Line Width'
          FocusControl = LineWidthComboBox2
        end
        object RadioGroup3: TRadioGroup
          Left = 8
          Top = 6
          Width = 81
          Height = 77
          Hint = 'Postion of vertical grid lines'
          HelpContext = 38
          Caption = 'Grid Lines'
          Enabled = False
          Items.Strings = (
            'None'
            'Minor'
            'Major')
          TabOrder = 0
          OnClick = RadioGroup3Click
        end
        object LineWidthComboBox2: TComboBox
          Left = 121
          Top = 22
          Width = 81
          Height = 21
          Hint = 'Line width of grid lines'
          HelpContext = 6
          TabOrder = 1
          OnChange = LineWidthComboBox2Change
        end
      end
    end
    object TabSheet3: TTabSheet
      HelpContext = 41
      Caption = '&Name'
      ImageIndex = 2
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox7: TGroupBox
        Left = 72
        Top = 152
        Width = 225
        Height = 89
        Hint = 'Variable name offsets from the top of the Y-axis'
        Caption = 'Offset From Top of Y-axis'
        TabOrder = 0
        OnExit = GroupBox7Exit
        object CheckBox6: TCheckBox
          Left = 160
          Top = 22
          Width = 57
          Height = 17
          Hint = 'Check to horizontally center the variable name over the graph'
          HelpContext = 44
          Caption = 'Center'
          Enabled = False
          TabOrder = 0
          OnClick = CheckBox6Click
        end
        object LabeledEdit12: TLabeledEdit
          Left = 62
          Top = 24
          Width = 89
          Height = 21
          Hint = 
            'Horizontal distance that the variable name is plotted from the Y' +
            '-axis'
          HelpContext = 43
          EditLabel.Width = 44
          EditLabel.Height = 13
          EditLabel.Caption = 'X Offset:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 1
          OnChange = LabeledEdit12Change
        end
        object LabeledEdit13: TLabeledEdit
          Left = 62
          Top = 56
          Width = 89
          Height = 21
          Hint = 
            'Vertical distance that the variable name is plotted from the top' +
            ' of the Y-axis'
          HelpContext = 45
          EditLabel.Width = 44
          EditLabel.Height = 13
          EditLabel.Caption = 'Y Offset:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 2
          OnChange = LabeledEdit13Change
        end
      end
      object GroupBox8: TGroupBox
        Left = 72
        Top = 32
        Width = 145
        Height = 97
        Hint = 'Options for variable name text'
        Caption = 'Text'
        TabOrder = 1
        OnExit = GroupBox8Exit
        object LabeledEdit11: TLabeledEdit
          Left = 56
          Top = 24
          Width = 65
          Height = 21
          Hint = 'Angle of variable name'
          HelpContext = 42
          EditLabel.Width = 31
          EditLabel.Height = 13
          EditLabel.Caption = 'Angle:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 0
          OnChange = LabeledEdit11Change
        end
        object BitBtn4: TBitBtn
          Left = 56
          Top = 56
          Width = 65
          Height = 25
          Hint = 'Variable name font'
          HelpContext = 20
          Caption = 'Font'
          DoubleBuffered = True
          Enabled = False
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            04000000000080000000CE0E0000D80E00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
            8888888888888888888888884444488844448888884488888448888888844888
            8448888888884444444888888888844884488088808888448448807870888884
            4448870007888888444888080888888884488808088888888888887078888888
            8888888088888888888888888888888888888888888888888888}
          ParentDoubleBuffered = False
          TabOrder = 1
          OnClick = BitBtn4Click
        end
      end
    end
    object TabSheet4: TTabSheet
      HelpContext = 46
      Caption = '&Truncate'
      ImageIndex = 3
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object CheckBox7: TCheckBox
        Left = 24
        Top = 32
        Width = 97
        Height = 17
        Hint = 'Check to truncate graphs'
        HelpContext = 46
        Caption = 'Truncate'
        Enabled = False
        TabOrder = 0
        OnClick = CheckBox7Click
      end
      object RadioGroup2: TRadioGroup
        Left = 120
        Top = 24
        Width = 121
        Height = 65
        Hint = 'Where to truncate graphs'
        HelpContext = 47
        Caption = 'Where to Truncate'
        Enabled = False
        Items.Strings = (
          'End of Graph'
          'End of Axis')
        TabOrder = 1
        OnClick = RadioGroup2Click
      end
      object GroupBox9: TGroupBox
        Left = 120
        Top = 104
        Width = 241
        Height = 145
        Hint = 'Options for printing truncated values'
        HelpContext = 48
        Caption = 'Print'
        TabOrder = 2
        object CheckBox8: TCheckBox
          Left = 8
          Top = 24
          Width = 137
          Height = 17
          Hint = 'Check to print truncated values'
          HelpContext = 48
          Caption = 'Print Truncated Values'
          Enabled = False
          TabOrder = 0
          OnClick = CheckBox8Click
        end
        object CheckBox9: TCheckBox
          Left = 8
          Top = 48
          Width = 145
          Height = 17
          Hint = 'Check to scale printed values the same as the X-axis'
          HelpContext = 48
          Caption = 'Scale Values as Tic Marks'
          Enabled = False
          TabOrder = 1
          OnClick = CheckBox9Click
        end
        object LabeledEdit14: TLabeledEdit
          Left = 136
          Top = 72
          Width = 73
          Height = 21
          Hint = 'Number of decimal points in printed truncated values'
          HelpContext = 48
          Color = clBtnFace
          EditLabel.Width = 125
          EditLabel.Height = 13
          EditLabel.Caption = 'Number of Decimal Points:'
          Enabled = False
          LabelPosition = lpLeft
          TabOrder = 2
          OnChange = LabeledEdit14Change
        end
        object BitBtn5: TBitBtn
          Left = 8
          Top = 104
          Width = 75
          Height = 25
          Hint = 'Font of printed truncated values'
          HelpContext = 20
          Caption = 'Font'
          DoubleBuffered = True
          Enabled = False
          Glyph.Data = {
            F6000000424DF600000000000000760000002800000010000000100000000100
            04000000000080000000CE0E0000D80E00001000000000000000000000000000
            8000008000000080800080000000800080008080000080808000C0C0C0000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
            8888888888888888888888884444488844448888884488888448888888844888
            8448888888884444444888888888844884488088808888448448807870888884
            4448870007888888444888080888888884488808088888888888887078888888
            8888888088888888888888888888888888888888888888888888}
          ParentDoubleBuffered = False
          TabOrder = 3
          OnClick = BitBtn5Click
        end
      end
    end
  end
  object Button2: TButton
    Left = 24
    Top = 16
    Width = 90
    Height = 25
    HelpContext = 12
    Caption = 'Select &Variables'
    TabOrder = 0
    OnClick = Button2Click
  end
  object Panel1: TPanel
    Left = 120
    Top = 16
    Width = 369
    Height = 25
    HelpContext = 12
    BevelInner = bvLowered
    TabOrder = 2
    object StaticText1: TStaticText
      Left = 8
      Top = 6
      Width = 106
      Height = 17
      Caption = 'No variables selected'
      TabOrder = 0
    end
  end
  object Button3: TButton
    Left = 16
    Top = 376
    Width = 75
    Height = 25
    Caption = '&Ok'
    ModalResult = 1
    TabOrder = 3
    OnClick = Button3Click
  end
  object CancelButton: TButton
    Left = 104
    Top = 376
    Width = 75
    Height = 25
    Caption = '&Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object Button5: TButton
    Left = 192
    Top = 376
    Width = 75
    Height = 25
    Caption = '&Help'
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 312
    Top = 376
    Width = 75
    Height = 25
    Hint = 'Apply changes and keep dialog box open'
    Caption = '&Apply'
    Enabled = False
    TabOrder = 6
    OnClick = Button6Click
  end
  object BitBtn1: TBitBtn
    Left = 400
    Top = 376
    Width = 89
    Height = 25
    HelpContext = 49
    Caption = 'Graph Style'
    DoubleBuffered = True
    Enabled = False
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      3333333333333333333333333333333333333FFF333333333333000333333333
      3333777FFF3FFFFF33330B000300000333337F777F777773F333000E00BFBFB0
      3333777F773333F7F333000E0BFBF0003333777F7F3337773F33000E0FBFBFBF
      0333777F7F3333FF7FFF000E0BFBF0000003777F7F3337777773000E0FBFBFBF
      BFB0777F7F33FFFFFFF7000E0BF000000003777F7FF777777773000000BFB033
      33337777773FF733333333333300033333333333337773333333333333333333
      3333333333333333333333333333333333333333333333333333333333333333
      3333333333333333333333333333333333333333333333333333}
    Layout = blGlyphRight
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 7
    OnClick = BitBtn1Click
  end
  object ColorDialog1: TColorDialog
    Left = 416
    Top = 40
  end
end
