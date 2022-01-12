object ConissForm: TConissForm
  Left = 1291
  Top = 211
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Constrained Incremental Sum of Squares'
  ClientHeight = 318
  ClientWidth = 425
  Color = clBtnFace
  ParentFont = True
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFF07FFFFFFF7FFFFFFF00007FFF7FFF7FF07FFF7FFFFFFF7FFFFFFF03FFFFF
    F7BF003FF7BFFFBFF7BFFF8007BFFFBFFFBF003FFFBFFFFFFFBFFFFFFF80FFFF
    FFBF03FFFFBFFBFFFFBFF87FFFBFFB7FFFBF037FFFBFFF7FFFBFFF00003FFF7F
    FFFF3F7FFFFFBF7FFFFF807FFFFFBFFFFFFF3FFFFFFFFFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 0
    Top = 0
    Width = 425
    Height = 1
    Style = bsRaised
  end
  object SpeedButton2: TSpeedButton
    Left = 392
    Top = 32
    Width = 23
    Height = 22
    Hint = 'Select dgx file'
    Glyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      0400000000008000000000000000000000001000000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333330080
      8800000033330070770033300033007777000000303300000000333330030000
      0000033330030FFFFFF0000000030FFFFFF0033333030CCC9CC0333333033339
      9933000333000399999333003303399999990000330333399933333000033339
      9933003033333339993330009999999993330033333333333333}
    ParentShowHint = False
    ShowHint = True
    OnClick = SpeedButton2Click
  end
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 148
    Height = 13
    Caption = 'Output file for diagram (*.dgx)'
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 64
    Width = 225
    Height = 81
    Caption = 'Type of Data'
    ItemIndex = 0
    Items.Strings = (
      'Counts'
      'Percentages'
      'Proportions')
    TabOrder = 1
    OnClick = RadioGroup1Click
  end
  object CheckBox1: TCheckBox
    Left = 96
    Top = 72
    Width = 129
    Height = 17
    Caption = 'Convert to proportions'
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object RadioGroup2: TRadioGroup
    Left = 8
    Top = 160
    Width = 409
    Height = 105
    Caption = 'Data Transformation/Dissimilarity Coefficient'
    ItemIndex = 0
    Items.Strings = (
      
        'Square root transformation (Edwards && Cavalli-Sforza'#39's chord di' +
        'stance)'
      
        'Sample vectors normalized to unit length (Orloci'#39's chord distanc' +
        'e)'
      
        'Variables standardized to mean 0, SD 1 (Standardized Euclidian d' +
        'istance)'
      'No data transformation (Euclidian distance)')
    TabOrder = 3
  end
  object RadioGroup3: TRadioGroup
    Left = 248
    Top = 64
    Width = 169
    Height = 60
    Caption = 'Type of Analysis'
    ItemIndex = 0
    Items.Strings = (
      'Stratigraphically constrained'
      'Unconstrained')
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 8
    Top = 32
    Width = 385
    Height = 21
    Hint = 'DGR file'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
  end
  object Button1: TButton
    Left = 112
    Top = 280
    Width = 89
    Height = 25
    Caption = 'Run Analysis'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 224
    Top = 280
    Width = 89
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 6
  end
  object OpenDialog1: TOpenDialog
    Left = 16
    Top = 272
  end
end
