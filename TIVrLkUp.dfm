object VarLookupForm: TVarLookupForm
  Left = 1105
  Top = 274
  BorderStyle = bsDialog
  Caption = 'Variable Lookup Files'
  ClientHeight = 259
  ClientWidth = 664
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object FlowPanel1: TFlowPanel
    Left = 8
    Top = 14
    Width = 642
    Height = 190
    AutoSize = True
    BevelOuter = bvNone
    TabOrder = 0
    object cxLabel1: TcxLabel
      Left = 0
      Top = 0
      AutoSize = False
      Caption = 'Taxa Names:'
      Height = 17
      Width = 642
    end
    object cxTextEdit1: TcxTextEdit
      Left = 0
      Top = 17
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 1
      Width = 560
    end
    object cxButton1: TcxButton
      Left = 560
      Top = 17
      Width = 75
      Height = 21
      Caption = 'Browse...'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 10
      OnClick = cxButton1Click
    end
    object cxLabel2: TcxLabel
      Left = 0
      Top = 38
      AutoSize = False
      Caption = 'Elements:'
      Height = 17
      Width = 642
    end
    object cxTextEdit2: TcxTextEdit
      Left = 0
      Top = 55
      Properties.OnChange = cxTextEdit2PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 2
      Width = 560
    end
    object cxButton2: TcxButton
      Left = 560
      Top = 55
      Width = 75
      Height = 21
      Caption = 'Browse...'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 12
      OnClick = cxButton2Click
    end
    object cxLabel3: TcxLabel
      Left = 0
      Top = 76
      AutoSize = False
      Caption = 'Units:'
      Height = 17
      Width = 642
    end
    object cxTextEdit3: TcxTextEdit
      Left = 0
      Top = 93
      Properties.OnChange = cxTextEdit2PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 4
      Width = 560
    end
    object cxButton3: TcxButton
      Left = 560
      Top = 93
      Width = 75
      Height = 21
      Caption = 'Browse...'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 5
      OnClick = cxButton3Click
    end
    object cxLabel4: TcxLabel
      Left = 0
      Top = 114
      AutoSize = False
      Caption = 'Contexts:'
      Height = 17
      Width = 642
    end
    object cxTextEdit4: TcxTextEdit
      Left = 0
      Top = 131
      Properties.OnChange = cxTextEdit2PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 6
      Width = 560
    end
    object cxButton4: TcxButton
      Left = 560
      Top = 131
      Width = 75
      Height = 21
      Caption = 'Browse...'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 7
      OnClick = cxButton4Click
    end
    object cxLabel5: TcxLabel
      Left = 0
      Top = 152
      AutoSize = False
      Caption = 'Taphonomy:'
      Height = 17
      Width = 642
    end
    object cxTextEdit5: TcxTextEdit
      Left = 0
      Top = 169
      Properties.OnChange = cxTextEdit2PropertiesChange
      Style.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 8
      Width = 560
    end
    object cxButton5: TcxButton
      Left = 560
      Top = 169
      Width = 75
      Height = 21
      Caption = 'Browse...'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 3
      OnClick = cxButton5Click
    end
  end
  object FlowPanel2: TFlowPanel
    Left = 257
    Top = 220
    Width = 150
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 1
    object cxButton6: TcxButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Ok'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      TabOrder = 1
    end
    object cxButton7: TcxButton
      Left = 75
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      TabOrder = 0
    end
  end
  object cxRadioGroup1: TcxRadioGroup
    Left = 8
    Top = 212
    Properties.Columns = 2
    Properties.Items = <
      item
        Caption = 'Short Form'
      end
      item
        Caption = 'Long Form'
      end>
    Style.LookAndFeel.NativeStyle = True
    StyleDisabled.LookAndFeel.NativeStyle = True
    StyleFocused.LookAndFeel.NativeStyle = True
    StyleHot.LookAndFeel.NativeStyle = True
    TabOrder = 2
    OnClick = cxRadioGroup1Click
    Height = 35
    Width = 185
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'xml'
    Filter = 'xml files|*.xml'
    Left = 552
    Top = 216
  end
end
