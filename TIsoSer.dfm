object IsotopeSeriesForm: TIsotopeSeriesForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Isotope Series'
  ClientHeight = 226
  ClientWidth = 282
  Color = 15984090
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object GridPanel1: TGridPanel
    Left = 0
    Top = 0
    Width = 282
    Height = 153
    Align = alTop
    Alignment = taLeftJustify
    BevelOuter = bvNone
    Color = 15984090
    ColumnCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 154.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 128.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = cxLabel1
        Row = 0
      end
      item
        Column = 1
        Control = cxSpinEdit1
        Row = 0
      end
      item
        Column = 0
        Control = cxLabel5
        Row = 1
      end
      item
        Column = 1
        Control = cxComboBox1
        Row = 1
      end
      item
        Column = 0
        Control = cxLabel7
        Row = 2
      end
      item
        Column = 1
        Control = cxComboBox3
        Row = 2
      end
      item
        Column = 0
        Control = cxLabel2
        Row = 3
      end
      item
        Column = 1
        Control = cxTextEdit1
        Row = 3
      end
      item
        Column = 0
        Control = cxLabel3
        Row = 4
      end
      item
        Column = 1
        Control = cxTextEdit2
        Row = 4
      end
      item
        Column = 0
        Control = cxLabel4
        Row = 5
      end
      item
        Column = 1
        Control = cxTextEdit3
        Row = 5
      end
      item
        Column = 0
        Control = cxLabel6
        Row = 6
      end
      item
        Column = 1
        Control = cxComboBox2
        Row = 6
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = False
    ParentFont = False
    RowCollection = <
      item
        SizeStyle = ssAuto
        Value = 50.000000000000000000
      end
      item
        SizeStyle = ssAuto
        Value = 100.000000000000000000
      end
      item
        SizeStyle = ssAuto
      end
      item
        SizeStyle = ssAuto
      end
      item
        SizeStyle = ssAuto
      end
      item
        SizeStyle = ssAuto
      end
      item
        SizeStyle = ssAuto
      end>
    ShowCaption = False
    TabOrder = 0
    object cxLabel1: TcxLabel
      Left = 5
      Top = 0
      Align = alRight
      Caption = '*Number of Samples in Series:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxSpinEdit1: TcxSpinEdit
      Left = 154
      Top = 0
      Align = alClient
      Properties.MaxValue = 1000.000000000000000000
      Style.BorderStyle = ebsFlat
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.BorderStyle = ebsUltraFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 0
      Width = 128
    end
    object cxLabel5: TcxLabel
      Left = 67
      Top = 21
      Align = alRight
      Caption = '*Sampling Origin:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxComboBox1: TcxComboBox
      Left = 154
      Top = 21
      Align = alClient
      Properties.DropDownListStyle = lsEditFixedList
      Properties.DropDownSizeable = True
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 1
      Width = 128
    end
    object cxLabel7: TcxLabel
      Left = 35
      Top = 42
      Align = alRight
      Caption = '*Sample Distance Units:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxComboBox3: TcxComboBox
      Left = 154
      Top = 42
      Align = alClient
      Properties.DropDownListStyle = lsEditFixedList
      Properties.Items.Strings = (
        'mm'
        'relative order')
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 2
      Text = 'mm'
      Width = 128
    end
    object cxLabel2: TcxLabel
      Left = 36
      Top = 63
      Align = alRight
      Caption = 'Sampling Interval (mm):'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxTextEdit1: TcxTextEdit
      Left = 154
      Top = 63
      Align = alClient
      Properties.ValidateOnEnter = True
      Properties.ValidationOptions = [evoRaiseException, evoShowErrorIcon]
      Properties.OnValidate = cxTextEdit1PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 3
      Width = 128
    end
    object cxLabel3: TcxLabel
      Left = 46
      Top = 84
      Align = alRight
      Caption = 'Transect Width (mm):'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxTextEdit2: TcxTextEdit
      Left = 154
      Top = 84
      Align = alClient
      Properties.ValidateOnEnter = True
      Properties.ValidationOptions = [evoRaiseException, evoShowErrorIcon]
      Properties.OnValidate = cxTextEdit2PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 4
      Width = 128
    end
    object cxLabel4: TcxLabel
      Left = 65
      Top = 105
      Align = alRight
      Caption = 'Drill Bit Size (mm):'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxTextEdit3: TcxTextEdit
      Left = 154
      Top = 105
      Align = alClient
      Properties.ValidateOnEnter = True
      Properties.ValidationOptions = [evoRaiseException, evoShowErrorIcon]
      Properties.OnValidate = cxTextEdit3PropertiesValidate
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 5
      Width = 128
    end
    object cxLabel6: TcxLabel
      Left = 24
      Top = 126
      Align = alRight
      Caption = 'Sampled Biological Marker:'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.IsFontAssigned = True
    end
    object cxComboBox2: TcxComboBox
      Left = 154
      Top = 126
      Align = alClient
      Properties.ClearKey = 46
      Properties.DropDownListStyle = lsEditFixedList
      Style.LookAndFeel.Kind = lfFlat
      Style.LookAndFeel.NativeStyle = False
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleDisabled.LookAndFeel.NativeStyle = False
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.NativeStyle = False
      StyleHot.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.NativeStyle = False
      TabOrder = 6
      Width = 128
    end
  end
  object cxLabel8: TcxLabel
    Left = 8
    Top = 159
    Caption = '* Required field'
    ParentFont = False
    Style.Font.Charset = DEFAULT_CHARSET
    Style.Font.Color = clRed
    Style.Font.Height = -11
    Style.Font.Name = 'Tahoma'
    Style.Font.Style = []
    Style.IsFontAssigned = True
  end
  object FlowPanel1: TFlowPanel
    Left = 79
    Top = 190
    Width = 140
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 2
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 70
      Height = 25
      Caption = 'Ok'
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'Blue'
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
      Left = 70
      Top = 0
      Width = 70
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.NativeStyle = False
      LookAndFeel.SkinName = 'Blue'
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
end
