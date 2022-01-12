object FuzzyForm: TFuzzyForm
  Left = 1327
  Top = 412
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Fuzzy Coordinates'
  ClientHeight = 261
  ClientWidth = 280
  Color = clBtnFace
  ParentFont = True
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000047
    7777777660004068888888888776468FFFFF88888887778FFFFFFFF88887788F
    FFFFFFFFFF87888FFFFFFFFFFF8888FFFFFFFFFFFF8888FFFFFFFFFFFF8888FF
    FFFFFFFFFF88888FFFFFFFFFF88878888FFFFFFFF888678888FFFFFFF8776788
    888FF88888770688888888888876047877777777776000000066464440000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object FlowPanel1: TFlowPanel
    Left = 65
    Top = 220
    Width = 150
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 0
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Ok'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 75
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      TabOrder = 1
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 208
    Top = 112
    Width = 60
    Height = 65
    Caption = 'Set'
    ItemIndex = 1
    Items.Strings = (
      'Point'
      'Box')
    TabOrder = 4
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 8
    Width = 249
    Height = 89
    Caption = 'True Coordinates'
    TabOrder = 1
    object Label1: TLabel
      Left = 15
      Top = 28
      Width = 43
      Height = 13
      Alignment = taRightJustify
      Caption = 'Latitude:'
    end
    object Label2: TLabel
      Left = 7
      Top = 60
      Width = 51
      Height = 13
      Alignment = taRightJustify
      Caption = 'Longitude:'
    end
    object cxPopupEdit1: TcxPopupEdit
      Left = 64
      Top = 24
      Properties.ImmediateDropDownWhenKeyPressed = False
      Properties.OnCloseUp = cxPopupEdit1PropertiesCloseUp
      Properties.OnPopup = cxPopupEdit1PropertiesPopup
      Style.BorderStyle = ebs3D
      Style.TextColor = clWindowText
      TabOrder = 0
      Width = 177
    end
    object cxPopupEdit2: TcxPopupEdit
      Left = 64
      Top = 56
      Properties.ImmediateDropDownWhenKeyPressed = False
      Properties.OnCloseUp = cxPopupEdit2PropertiesCloseUp
      Properties.OnPopup = cxPopupEdit2PropertiesPopup
      Style.BorderStyle = ebs3D
      Style.TextColor = clWindowText
      TabOrder = 1
      Width = 177
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 112
    Width = 177
    Height = 89
    Caption = 'Fuzzy Parameters'
    TabOrder = 2
    object LabeledEdit1: TLabeledEdit
      Left = 124
      Top = 24
      Width = 45
      Height = 21
      EditLabel.Width = 112
      EditLabel.Height = 13
      EditLabel.Caption = 'Minimum Distance (km):'
      LabelPosition = lpLeft
      TabOrder = 0
      Text = '1'
    end
    object LabeledEdit2: TLabeledEdit
      Left = 124
      Top = 56
      Width = 45
      Height = 21
      EditLabel.Width = 116
      EditLabel.Height = 13
      EditLabel.Caption = 'Maximum Distance (km):'
      LabelPosition = lpLeft
      TabOrder = 1
      Text = '5'
    end
  end
  object CheckBox1: TCheckBox
    Left = 208
    Top = 184
    Width = 97
    Height = 17
    Caption = 'Add Note'
    Checked = True
    State = cbChecked
    TabOrder = 3
  end
end
