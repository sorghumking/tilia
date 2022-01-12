object ConcForm: TConcForm
  Left = 1331
  Top = 163
  BorderStyle = bsDialog
  Caption = 'Concentrations'
  ClientHeight = 501
  ClientWidth = 392
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 96
    Width = 87
    Height = 13
    Caption = 'Groups to include:'
  end
  object Label4: TLabel
    Left = 120
    Top = 272
    Width = 125
    Height = 13
    Caption = 'Quantity of spike medium:'
  end
  object Label5: TLabel
    Left = 120
    Top = 360
    Width = 151
    Height = 13
    Caption = 'Concentration of spike medium:'
  end
  object Label3: TLabel
    Left = 120
    Top = 184
    Width = 95
    Height = 13
    Caption = 'Quantity of sample:'
  end
  object Label2: TLabel
    Left = 120
    Top = 96
    Width = 29
    Height = 13
    Caption = 'Spike:'
  end
  object cxCheckListBox1: TcxCheckListBox
    Left = 16
    Top = 112
    Width = 89
    Height = 137
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 1
  end
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 16
    Width = 361
    Height = 73
    Caption = 'Method'
    ItemIndex = 0
    Items.Strings = (
      
        'Quantity of sample, Quantity of spike medium, Conc of spike medi' +
        'um'
      'Quantity of sample, Quantity of spike added to sample'
      'Quantity of sample examined')
    TabOrder = 0
    OnClick = RadioGroup1Click
  end
  object cxCheckListBox4: TcxCheckListBox
    Left = 120
    Top = 288
    Width = 257
    Height = 69
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 4
  end
  object cxCheckListBox5: TcxCheckListBox
    Left = 120
    Top = 376
    Width = 257
    Height = 69
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 5
  end
  object cxCheckListBox3: TcxCheckListBox
    Left = 120
    Top = 200
    Width = 257
    Height = 69
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 3
  end
  object Button1: TButton
    Left = 96
    Top = 464
    Width = 89
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 8
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 208
    Top = 464
    Width = 89
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 9
  end
  object cxCheckListBox2: TcxCheckListBox
    Left = 120
    Top = 112
    Width = 257
    Height = 69
    Items = <>
    Style.BorderStyle = cbs3D
    TabOrder = 2
  end
  object Button3: TButton
    Left = 16
    Top = 256
    Width = 89
    Height = 25
    Caption = 'Include All'
    TabOrder = 6
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 16
    Top = 304
    Width = 89
    Height = 25
    Caption = 'Default Codes'
    TabOrder = 7
    OnClick = Button4Click
  end
  object RadioGroup2: TRadioGroup
    Left = 16
    Top = 376
    Width = 89
    Height = 65
    Caption = 'Null Values:'
    ItemIndex = 0
    Items.Strings = (
      'Skip'
      ' Zero')
    TabOrder = 10
  end
end
