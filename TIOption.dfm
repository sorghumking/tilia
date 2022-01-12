object SSOptionsForm: TSSOptionsForm
  Left = 1465
  Top = 185
  BorderStyle = bsDialog
  Caption = 'Spreadsheet Options'
  ClientHeight = 465
  ClientWidth = 487
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 100
    Width = 108
    Height = 13
    Alignment = taRightJustify
    Caption = 'Default Column Width:'
  end
  object Label4: TLabel
    Left = 27
    Top = 76
    Width = 97
    Height = 13
    Alignment = taRightJustify
    Caption = 'Default Row Height:'
  end
  object Label5: TLabel
    Left = 192
    Top = 76
    Width = 53
    Height = 13
    Alignment = taRightJustify
    Caption = 'Undo Limit:'
  end
  object Label8: TLabel
    Left = 216
    Top = 238
    Width = 112
    Height = 13
    Alignment = taRightJustify
    Caption = 'Internet Timeout (sec):'
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 8
    Width = 229
    Height = 57
    Caption = 'Spreadsheet Font'
    TabOrder = 0
    object Label2: TLabel
      Left = 172
      Top = 8
      Width = 23
      Height = 13
      Caption = 'Size:'
    end
    object cxFontNameComboBox1: TcxFontNameComboBox
      Left = 8
      Top = 24
      Style.BorderStyle = ebs3D
      TabOrder = 0
      Width = 153
    end
    object cxSpinEdit4: TcxSpinEdit
      Left = 172
      Top = 24
      Properties.AssignedValues.MaxValue = True
      Properties.AssignedValues.MinValue = True
      Style.BorderStyle = ebs3D
      TabOrder = 1
      Width = 49
    end
  end
  object GroupBox1: TGroupBox
    Left = 378
    Top = 8
    Width = 97
    Height = 121
    Caption = 'Show Columns'
    TabOrder = 1
    object CheckBox1: TCheckBox
      Left = 8
      Top = 20
      Width = 57
      Height = 17
      Caption = 'Codes'
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 8
      Top = 36
      Width = 65
      Height = 17
      Caption = 'Elements'
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 8
      Top = 52
      Width = 49
      Height = 17
      Caption = 'Units'
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 8
      Top = 68
      Width = 65
      Height = 17
      Caption = 'Context'
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 8
      Top = 84
      Width = 81
      Height = 17
      Caption = 'Taphonomy'
      TabOrder = 4
    end
    object CheckBox6: TCheckBox
      Left = 8
      Top = 100
      Width = 65
      Height = 17
      Caption = 'Groups'
      TabOrder = 5
    end
  end
  object cxSpinEdit2: TcxSpinEdit
    Left = 128
    Top = 96
    Properties.MaxValue = 1000.000000000000000000
    Properties.MinValue = 20.000000000000000000
    Style.BorderStyle = ebs3D
    TabOrder = 2
    Value = 20
    Width = 49
  end
  object cxSpinEdit3: TcxSpinEdit
    Left = 128
    Top = 72
    Properties.MaxValue = 100.000000000000000000
    Properties.MinValue = 4.000000000000000000
    Style.BorderStyle = ebs3D
    TabOrder = 3
    Value = 10
    Width = 49
  end
  object GroupBox3: TGroupBox
    Left = 247
    Top = 8
    Width = 121
    Height = 57
    Caption = 'Codes'
    TabOrder = 4
    object CheckBox7: TCheckBox
      Left = 8
      Top = 20
      Width = 105
      Height = 17
      Caption = 'Check Duplicates'
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object CheckBox8: TCheckBox
      Left = 8
      Top = 36
      Width = 97
      Height = 17
      Caption = 'Case Sensitive'
      TabOrder = 1
    end
  end
  object cxSpinEdit5: TcxSpinEdit
    Left = 248
    Top = 72
    Properties.LargeIncrement = 1.000000000000000000
    Properties.MaxValue = 20.000000000000000000
    Properties.MinValue = 1.000000000000000000
    Style.BorderStyle = ebs3D
    TabOrder = 6
    Value = 10
    Width = 49
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 136
    Width = 145
    Height = 93
    Caption = 'Decimal Places'
    TabOrder = 5
    object Label6: TLabel
      Left = 7
      Top = 44
      Width = 77
      Height = 13
      Alignment = taRightJustify
      Caption = 'Concentrations:'
    end
    object Label3: TLabel
      Left = 38
      Top = 20
      Width = 46
      Height = 13
      Alignment = taRightJustify
      Caption = 'Percents:'
    end
    object Label7: TLabel
      Left = 52
      Top = 68
      Width = 32
      Height = 13
      Alignment = taRightJustify
      Caption = 'Influx:'
    end
    object cxSpinEdit1: TcxSpinEdit
      Left = 88
      Top = 16
      Properties.AssignedValues.MinValue = True
      Properties.MaxValue = 15.000000000000000000
      Style.BorderStyle = ebs3D
      TabOrder = 0
      Width = 49
    end
    object cxSpinEdit6: TcxSpinEdit
      Left = 88
      Top = 40
      Properties.AssignedValues.MinValue = True
      Properties.MaxValue = 15.000000000000000000
      Style.BorderStyle = ebs3D
      TabOrder = 1
      Width = 49
    end
    object cxSpinEdit7: TcxSpinEdit
      Left = 88
      Top = 64
      Properties.AssignedValues.MinValue = True
      Properties.MaxValue = 15.000000000000000000
      Style.BorderStyle = ebs3D
      TabOrder = 2
      Width = 49
    end
  end
  object RadioGroup1: TRadioGroup
    Left = 163
    Top = 135
    Width = 145
    Height = 93
    Caption = 'Second Header Row'
    ItemIndex = 0
    Items.Strings = (
      'Analysis Unit Name'
      'Collection Unit Name'
      'Collection Unit Handle'
      'Site Name')
    TabOrder = 7
  end
  object GroupBox5: TGroupBox
    Left = 8
    Top = 259
    Width = 466
    Height = 52
    Caption = 'Lookup File Path:'
    TabOrder = 8
    object cxShellComboBox1: TcxShellComboBox
      Left = 136
      Top = 20
      Enabled = False
      Properties.DropDownWidth = 317
      Properties.ShowFullPath = sfpAlways
      Properties.StoreRelativePath = False
      Properties.ViewOptions = [scvoShowHidden]
      Style.BorderStyle = ebs3D
      Style.LookAndFeel.Kind = lfOffice11
      Style.LookAndFeel.NativeStyle = True
      Style.Shadow = False
      Style.PopupBorderStyle = epbsDefault
      StyleDisabled.LookAndFeel.Kind = lfOffice11
      StyleDisabled.LookAndFeel.NativeStyle = True
      StyleFocused.LookAndFeel.Kind = lfOffice11
      StyleFocused.LookAndFeel.NativeStyle = True
      StyleHot.LookAndFeel.Kind = lfOffice11
      StyleHot.LookAndFeel.NativeStyle = True
      TabOrder = 0
      Width = 320
    end
    object cxRadioButton1: TcxRadioButton
      Left = 8
      Top = 22
      Width = 57
      Height = 17
      BiDiMode = bdLeftToRight
      Caption = 'Default'
      Checked = True
      ParentBiDiMode = False
      TabOrder = 1
      TabStop = True
      OnClick = cxRadioButton1Click
      LookAndFeel.NativeStyle = True
    end
    object cxRadioButton2: TcxRadioButton
      Left = 71
      Top = 22
      Width = 57
      Height = 17
      BiDiMode = bdLeftToRight
      Caption = 'Custom'
      ParentBiDiMode = False
      TabOrder = 2
      OnClick = cxRadioButton2Click
      LookAndFeel.NativeStyle = True
    end
  end
  object FlowPanel1: TFlowPanel
    Left = 168
    Top = 430
    Width = 150
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 9
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 75
      Height = 25
      Caption = 'Ok'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      OptionsImage.Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        000000000000000000000000000A000000250000003300000033000000330000
        0033000000250000000A00000000000000000000000000000000000000000000
        00000000000000000022001D105C006738C9008C4BFF008B4AFF008B4AFF008C
        4BFF006738C9001D105C0000001E000000000000000000000000000000000000
        00000000001E005E33BB009050FF01A169FF01AB76FF01AC79FF01AC79FF01AB
        76FF01A169FF009050FF00532DAA0000001E0000000000000000000000000000
        000A00532DAA009152FF02AC77FF00C38CFF00D79BFF00DA9CFF00DA9CFF00D7
        9CFF01C38CFF01AB76FF009253FF00532DAA0000000A0000000000000000001C
        1051009051FF0FB483FF00D298FF00D598FF00D192FF00CF90FF00D091FF00D3
        96FF00D69BFF00D198FF01AB76FF009050FF001D105100000000000000000067
        36C916AB78FF10C996FF00D397FF00CD8CFFFFFFFFFFFFFFFFFFFFFFFFFF00CC
        8CFF00D195FF00D59BFF01C18CFF01A169FF006838C90000000000000000008A
        48FF39C49DFF00D198FF00CB8CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF00CA8CFF00CF96FF00D29BFF01AB76FF008C4BFF00000000000000000089
        46FF52D2B0FF00CC92FFFFFFFFFFFFFFFFFFFFFFFFFF00C484FFFFFFFFFFFFFF
        FFFFFFFFFFFF00C88DFF00D09AFF00AD79FF008B4AFF00000000000000000088
        45FF68DDBEFF00C991FFFFFFFFFFFFFFFFFF00C68CFF00C891FF00C58BFFFFFF
        FFFFFFFFFFFFFFFFFFFF00CC96FF00AD78FF008B4AFF00000000000000000088
        46FF76E0C6FF00CB98FF00C590FF00C691FF00C895FF00C997FF00C894FF00C3
        8CFFFFFFFFFFFFFFFFFF00C792FF00AB75FF008C4BFF00000000000000000065
        34BE59C9A4FF49DEBCFF00C794FF00C897FF00C998FF00C999FF00C998FF00C7
        94FF00C38EFFFFFFFFFF00BD8AFF00A067FF006838BF0000000000000000001C
        0F330A9458FFADF8E9FF18D0A7FF00C495FF00C697FF00C698FF00C798FF00C7
        98FF00C697FF00C596FF12B585FF008F50FF001C0F3300000000000000000000
        0000005C30AA199C63FFBCFFF7FF5EE4C9FF00C59AFF00C396FF00C497FF00C5
        9AFF22CAA2FF2FC196FF029355FF00522C950000000000000000000000000000
        00000000000000512A950E9659FF74D5B6FFA0F4E1FF94EFDCFF7CE6CCFF5ED6
        B5FF2EB587FF039152FF005D33AA000000000000000000000000000000000000
        00000000000000000000001C0F33006433BB008744FF008743FF008744FF0089
        46FF006636BB001C0F3300000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000}
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
      OptionsImage.Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000000000000000
        0000000000000000001200000033000000330000003300000033000000330000
        0033000000330000001200000000000000000000000000000000000000000000
        0000000000121116457C2C3CC0FF2B3BBEFF2B3ABEFF2B3ABEFF2B3ABEFF2B3B
        BEFF2C3CC0FF1116457C00000012000000000000000000000000000000000000
        0012101543792F3EC3FF5F71F9FF697DFFFF697CFFFF697CFFFF697CFFFF697D
        FFFF5F71F9FF2F3EC3FF10154379000000120000000000000000000000121015
        43792F3EC2FF586BF6FF5F74FFFF5D72FEFF5E72FDFF5E73FDFF5E72FDFF5D72
        FEFF5F74FFFF586BF6FF2F3EC2FF1015437900000012000000001116457C303F
        C2FF5568F3FF586CFCFF4E64F9FF4D63F8FF5468F9FF576BF9FF5468F9FF4D63
        F8FF4E64F9FF586CFCFF5568F3FF303FC2FF1116457C000000002D3DC0FF5367
        F2FF556BFAFF4960F7FFFFFFFFFFFFFFFFFF3E56F6FF475EF6FF3E56F6FFFFFF
        FFFFFFFFFFFF4960F7FF556BFAFF5166F2FF2D3DC0FF000000002B3BBFFF6276
        FCFF4D64F6FF4259F4FFFFFFFFFFFFFFFFFFFFFFFFFF2C46F3FFFFFFFFFFFFFF
        FFFFFFFFFFFF4259F4FF4E64F6FF5F75FCFF2C3BBFFF000000002A3ABFFF7386
        FAFF495FF3FF435AF3FF6E80F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF6E80F6FF435AF3FF495FF3FF6E81FAFF2B3ABFFF000000002939BFFF8696
        FBFF425AF1FF4259F1FF354EF0FF5B70F2FFFFFFFFFFFFFFFFFFFFFFFFFF5B70
        F2FF354EF0FF4259F1FF435BF1FF7D90F9FF2A39BFFF000000002737BFFF9AA8
        FBFF3A55EFFF3953EEFF2844EDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFF2844EDFF3953EEFF3B55EFFF8E9DFAFF2838BFFF000000002637BFFF9FAB
        F1FF314CEDFF2B47EBFFFFFFFFFFFFFFFFFFFFFFFFFF5369EFFFFFFFFFFFFFFF
        FFFFFFFFFFFF2C47EBFF314CEDFF9FABF1FF2737BFFF000000002838C1FF9FAB
        F1FF8091F4FF213EE8FFFFFFFFFFFFFFFFFF5D72EEFF2340E8FF5D72EEFFFFFF
        FFFFFFFFFFFF213EE8FF8091F4FF9FABF1FF2838C1FF000000001016455B2E3E
        C3FF97A5EFFF778AF2FF5B71EEFF6074EEFF2643E6FF2C48E7FF2643E6FF6074
        EEFF5B71EEFF778AF2FF97A5EFFF2E3EC3FF1016455B00000000000000000F15
        43582E3EC2FF95A2EEFF7688F0FF1E3BE4FF2340E5FF2541E5FF2340E5FF1E3B
        E4FF7688F0FF95A2EEFF2E3EC2FF0F1543580000000000000000000000000000
        00000F1543582F3DC3FF94A0EFFFADB9F8FFADB8F7FFADB9F7FFADB8F7FFADB9
        F8FF94A0EFFF2F3DC3FF0F154358000000000000000000000000000000000000
        0000000000001015455B303FC4FF4555CEFF4454CDFF4354CDFF4454CDFF4555
        CEFF303FC4FF1015455B00000000000000000000000000000000}
      TabOrder = 1
    end
  end
  object CheckBox9: TCheckBox
    Left = 8
    Top = 236
    Width = 195
    Height = 17
    Caption = 'Add Syonyms to Taxa Lookup List'
    TabOrder = 11
  end
  object cxSpinEdit8: TcxSpinEdit
    Left = 330
    Top = 234
    Properties.Increment = 10.000000000000000000
    Properties.LargeIncrement = 60.000000000000000000
    Properties.MaxValue = 300.000000000000000000
    Properties.MinValue = 60.000000000000000000
    Style.BorderStyle = ebs3D
    TabOrder = 10
    Value = 60
    Width = 49
  end
  object CheckBox10: TCheckBox
    Left = 367
    Top = 150
    Width = 97
    Height = 17
    Caption = 'Use Google Maps'
    Checked = True
    State = cbChecked
    TabOrder = 12
  end
  object GroupBox6: TGroupBox
    Left = 8
    Top = 317
    Width = 466
    Height = 52
    Caption = 'Neotoma Tilia API Endpoint:'
    TabOrder = 13
    object cxTextEdit1: TcxTextEdit
      Left = 8
      Top = 20
      TabOrder = 0
      Width = 448
    end
  end
  object GroupBox7: TGroupBox
    Left = 8
    Top = 370
    Width = 466
    Height = 52
    Caption = 'Neotoma OxCal API Endpoint:'
    TabOrder = 14
    object cxTextEdit2: TcxTextEdit
      Left = 8
      Top = 20
      TabOrder = 0
      Width = 448
    end
  end
end
