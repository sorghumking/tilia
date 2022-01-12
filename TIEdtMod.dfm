object EditModifiersForm: TEditModifiersForm
  Left = 414
  Top = 136
  BorderStyle = bsDialog
  Caption = 'Edit Units'
  ClientHeight = 275
  ClientWidth = 312
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 16
    Width = 79
    Height = 13
    Caption = 'Dataset Type:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
  end
  object Label2: TLabel
    Left = 159
    Top = 16
    Width = 29
    Height = 13
    Caption = 'Units'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
  end
  object SpeedButton2: TSpeedButton
    Left = 281
    Top = 8
    Width = 23
    Height = 22
    Hint = 'Enforce lowercase when depressed'
    AllowAllUp = True
    GroupIndex = 2
    Down = True
    Flat = True
    Glyph.Data = {
      AA030000424DAA03000000000000360000002800000011000000110000000100
      18000000000074030000C40E0000C40E00000000000000000000FFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFBF9F7EACEB0E4BE95E7C6A2F4E9DCFCF9F6EDD5
      BCE4BF96E7C5A0F6EDE1FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      E9CEB0CE8B41CC8639CD873BD29450E7C7A5D1914DCC8639CC8536D8A46CFFFF
      FF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE3BE95CE883ACF8B3FD9A46A
      E6C5A1D1914BCE893DD08B41D8A266F4EBDFFFFFFF00FFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFE6CAA9D18E43D18D42E3BF97FBFDFDEAD0B3CF8B3FD29147
      D8A165FFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3EFEAD9
      A870D38F41D9A56AF4EDE3F0E0CCD39042D89B50D8A265FFFFFFFFFFFF00FFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFEFEE8C5A2D89A58D59D5FE9
      CEAED8984ADFA55AD8A466FFFFFFFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FF7FBA9580BD9A7FBE9B80BD9AB7C8AAE3BD96D59D60D7974CDDA358D7A366F4
      F8FAFFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFAF4F78FC6A500A26000C28606BA
      777FBD9AF9F6F9E7D2B5D39043D89A4FD7A265F3F7F9FFFFFF00EADBCBE9D8C7
      FFFFFFFFFFFFFAE9E48FCBAD01B0780ED3A326CF9A80BC9AF8F6FAE6D4BECF8A
      3DD28F44D6A165F1F5F7FFFFFF00D8A874D29554EDE8E4F6F3F69BB18700AA76
      1AD0AA2AC79A1BAA717FB58EF3E7E0D9AD7DCD863ACD8537DEBB95EFF2F3FFFF
      FF00E7D7C7D6A167F0F8FDF8F7FD409E6A60E9D73EBE9596CFB68FAA7C718943
      D7924ECC8433CE893FDBB286ECEBE8FFFFFFFFFFFF00FFFFFFDEB686D8984DDC
      A25FE797493B8A459CBE9DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFF00FFFFFFE7DCCFE2B881E8D9C3E2A964E7AA67EFDFD3FF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFF
      FFFFFFFFE0B47CDFB076DD9F53E1BB8BEAEBEEFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFFE2CEB6D59447D693
      45E6DDD3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFF00FFFFFFFFFFFFE4DED7D49D61D5A065E7EAEEFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00FFFFFFFFFFFF
      E5E5E6D9B38ADCC4AAE5E6E7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFF00}
    ParentShowHint = False
    ShowHint = True
  end
  object Label3: TLabel
    Left = 8
    Top = 133
    Width = 93
    Height = 13
    Caption = 'New Dataset Type:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 159
    Top = 133
    Width = 52
    Height = 13
    Caption = 'New Units:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object cxComboBox1: TcxComboBox
    Left = 8
    Top = 148
    ParentShowHint = False
    Properties.OnChange = cxComboBox1PropertiesChange
    ShowHint = False
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 1
    Width = 145
  end
  object FlowPanel1: TFlowPanel
    Left = 56
    Top = 176
    Width = 48
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 2
    object cxButton1: TcxButton
      Left = 0
      Top = 0
      Width = 24
      Height = 25
      Hint = 'Add new Taxa Group'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 0
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 24
      Top = 0
      Width = 24
      Height = 25
      Hint = 'Delete Taxa Group'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 1
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = cxButton2Click
    end
  end
  object cxListBox1: TcxListBox
    Left = 8
    Top = 32
    Width = 145
    Height = 97
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = False
    Sorted = True
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 3
    OnClick = cxListBox1Click
  end
  object cxListBox2: TcxListBox
    Left = 159
    Top = 32
    Width = 145
    Height = 97
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = False
    Sorted = True
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 4
    OnClick = cxListBox2Click
  end
  object cxTextEdit1: TcxTextEdit
    Left = 159
    Top = 149
    ParentShowHint = False
    Properties.OnChange = cxTextEdit1PropertiesChange
    ShowHint = False
    Style.LookAndFeel.Kind = lfFlat
    StyleDisabled.LookAndFeel.Kind = lfFlat
    StyleFocused.LookAndFeel.Kind = lfFlat
    StyleHot.LookAndFeel.Kind = lfFlat
    TabOrder = 0
    Width = 145
  end
  object FlowPanel2: TFlowPanel
    Left = 207
    Top = 176
    Width = 48
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 5
    object cxButton3: TcxButton
      Left = 0
      Top = 0
      Width = 24
      Height = 25
      Hint = 'Add new Units'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 0
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = cxButton3Click
    end
    object cxButton4: TcxButton
      Left = 24
      Top = 0
      Width = 24
      Height = 25
      Hint = 'Delete Units'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 1
      OptionsImage.Images = cxImageList1
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = cxButton4Click
    end
  end
  object FlowPanel3: TFlowPanel
    Left = 18
    Top = 220
    Width = 276
    Height = 25
    AutoSize = True
    AutoWrap = False
    BevelOuter = bvNone
    TabOrder = 6
    object cxButton5: TcxButton
      Left = 0
      Top = 0
      Width = 69
      Height = 25
      Caption = 'Ok'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      OptionsImage.ImageIndex = 2
      OptionsImage.Images = cxImageList1
      TabOrder = 0
      OnClick = cxButton5Click
    end
    object cxButton6: TcxButton
      Left = 69
      Top = 0
      Width = 69
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      OptionsImage.ImageIndex = 4
      OptionsImage.Images = cxImageList1
      TabOrder = 1
    end
    object cxButton7: TcxButton
      Left = 138
      Top = 0
      Width = 69
      Height = 25
      Caption = 'Save'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 3
      OptionsImage.Images = cxImageList1
      TabOrder = 2
      OnClick = cxButton7Click
    end
    object cxButton8: TcxButton
      Left = 207
      Top = 0
      Width = 69
      Height = 25
      Caption = 'Upload'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 5
      OptionsImage.Images = cxImageList1
      TabOrder = 3
      OnClick = cxButton8Click
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 256
    Width = 312
    Height = 19
    Panels = <>
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 11534344
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00000000000000000000000301080D34135A3D7549A0659C73C3679E74C44178
          4DA3103916600004010B00000000000000000000000000000000000000000000
          000000000000092F0F525DB97EE5A7F6D3FFBDFBE2FFCDFDEAFFCCFDEAFFBBFA
          E1FFA5F6D2FF61C084EA0C38145D000000000000000000000000000000000000
          00000C4517744ED081FE67E6A5FF8BF1C1FFAFEAD0FFC8DDD4FFC8DDD4FFAEEA
          D0FF89F0BFFF65E5A3FF4CD181FF10501C830000000000000000000000000328
          094D22AE4DFE2EC669FF4DDA8CFF6BE7A8FFA6E6C7FFE0E0E0FFE0E0E0FFA5E6
          C6FF69E7A7FF4BD98AFF2CC466FF20AE4CFF05330C5D00000000000200050F7E
          24E00D9E35FF1AB34DFF30C76BFF47D785FF92E0B6FFE9E9E9FFE9E9E9FF91E0
          B6FF46D684FF2FC669FF18B24CFF0D9D34FF108326EA0004010B012605500780
          1CFF078E26FF0EA036FF17B049FF25BE5DFF7FD5A0FFF1F1F1FFF1F1F1FF7ED5
          A0FF24BD5CFF16AF48FF0D9E35FF078D25FF067F1BFF01310861094C12934398
          50FF63AB70FF7ABB89FF7CC28FFF7FC795FFB2DCC0FFF8F8F8FFF8F8F8FFB2DC
          C0FF7EC795FF7CC28FFF79BB89FF61AA6FFF439850FF0D5416A31D6425B45A9E
          62FFB7D5BCFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFDFDFFFDFD
          FDFFFDFDFDFFFDFDFDFFFDFDFDFFB8D5BCFF5A9E63FF256D2DC4206328B3659F
          6AFFBED6C1FFFCFCFCFFFCFCFCFFFCFCFCFFFCFCFCFFFCFCFCFFFCFCFCFFFCFC
          FCFFFCFCFCFFFCFCFCFFFCFCFCFFBFD6C1FF66A06BFF296D31C3154F1C9070A2
          74FFA3C4A6FFBDD5BFFFC2DAC5FFC7DECAFFDBE7DCFFF7F7F7FFF7F7F7FFDBE7
          DCFFC8DECAFFC3DAC5FFBDD5BFFFA4C4A7FF71A375FF1D5924A00424084B77A5
          7AFFA1C1A3FFACCAAEFFB6D1B8FFBED7C0FFD2E0D4FFEFEFEFFFEFEFEFFFD3E0
          D4FFBED7C0FFB6D2B8FFADCAAFFFA2C1A4FF7BA67EFF07300C5B000100034885
          4EDAABC5ACFFBDD3BEFFC7DAC8FFCFE0D1FFDAE2DAFFE7E7E7FFE7E7E7FFDAE3
          DBFFD0E0D1FFC8DAC9FFBDD3BEFFADC7AEFF538F59E500030108000000000623
          094394B996FCCBDBCBFFD5E2D5FFDDE8DEFFDFE4DFFFDFDFDFFFDFDFDFFFDFE4
          DFFFDEE8DEFFD5E2D6FFCCDBCCFF9CBE9EFE0A2D0E5200000000000000000000
          0000103A1565AFCCB1FCDFE8DFFFE7EEE7FFEAEEEAFFE9EAE9FFE9EAE9FFEAEE
          EAFFE8EEE8FFDFE8E0FFB7D1B8FE17441C730000000000000000000000000000
          00000000000008250C4375A47ADAE4EDE5FFF4F7F4FFF9FBF9FFF9FBF9FFF5F8
          F5FFE7EFE8FF7EAC84E00B2B0F4C000000000000000000000000000000000000
          000000000000000000000001000309280D4A35633B905C8862B35E8A64B43967
          3F930B2D104F0002000500000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          000000000000000000000000001800000078000A12BB011E31DB011E31DB000A
          12BB000000780000001800000000000000000000000000000000000000000000
          00000000000100000077012854F50F6EC9FF299CF7FF36A8F8FF36A9F8FF299C
          F7FF0F6FC9FF012854F500000077000000010000000000000000000000000000
          0001000206A00348AAFF1C80F9FF3294F9FF329BF8FF329FF8FF329FF8FF329B
          F8FF3294F9FF1C80F8FF0348AAFF000206A00000000100000000000000000000
          0077023EAAFF0A67F9FF1376F9FF137DF8FF1383F8FF1487F8FF1487F8FF1383
          F8FF137DF8FF1376F9FF0A68F9FF023EAAFF000000770000000000000018011A
          55F50355FAFF045EF9FF0566F9FF066DF8FF0672F8FF0675F8FF0675F8FF0672
          F8FF066DF8FF0566F9FF045EF9FF0355FAFF011A55F500000018000000780238
          CBFF034EFAFF0456FAFF045DF9FF0463F9FF0467F9FF0469F9FF0469F9FF0467
          F9FF0463F9FF045DF9FF0456FAFF034EFAFF0239CBFF00000078000412BB023E
          FBFF0347FBFF6593FCFF91B5FCFF91B8FCFF91B9FCFF91BAFCFF91BAFCFF91B9
          FCFF91B8FCFF91B5FCFF6593FCFF0347FBFF023EFBFF000412BB000932DB0237
          FBFF0B45FBFFB3C6FDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFB3C6FDFF0B45FBFF0237FBFF000932DB000833DB0632
          FCFF1545FBFFB6C6FEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFFB6C6FEFF1545FBFF0632FCFF000933DB000212BB092C
          FCFF254AFCFF7B8EF5FFA2ABF2FFA2ACF2FFA2ADF2FFA2ADF2FFA2ADF2FFA2AD
          F2FFA2ACF2FFA2ABF2FF7B8EF5FF254AFCFF092CFCFF000212BB00000078031A
          CDFF3752FDFF3958FDFF395BFDFF395EFDFF395FFDFF3960FDFF3960FDFF395F
          FDFF395EFDFF395BFDFF3958FDFF3752FDFF031ACDFF00000078000000180008
          56F52F43FDFF5266FEFF5269FEFF526BFDFF526CFDFF526DFDFF526DFDFF526C
          FDFF526BFDFF5269FEFF5266FEFF2F43FDFF000856F500000018000000000000
          00770611ADFF5B67FEFF707DFEFF707EFEFF707FFEFF7080FEFF7080FEFF707F
          FEFF707EFEFF707DFEFF5B68FEFF0611ADFF0000007700000000000000000000
          0001000006A00A11ADFF6068FEFF9299FEFF9299FFFF929AFFFF929AFFFF9299
          FFFF9299FEFF6068FEFF0A11ADFF000006A00000000100000000000000000000
          00000000000100000077000256F52024CEFF585CFEFF7377FFFF7377FFFF585C
          FEFF2024CEFF000256F500000077000000010000000000000000000000000000
          000000000000000000000000001800000078000012BB000033DB000033DB0000
          12BB000000780000001800000000000000000000000000000000}
      end
      item
        Image.Data = {
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
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          00006D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D42
          2FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF6D422FFF00000000CE72
          6FFFD19792FFCB8E8AFF715A48FFC0B2ABFFC4BCB8FFCAC1BCFFCAC1BCFFCAC1
          BCFFCAC1BCFF8C7667FF944340FF944340FF944340FF6D422FFF00000000CE72
          6FFFD79F9BFFD19792FF715A48FF2E1F18FF5F5046FFFFFFFFFFFFFFFFFFFFFF
          FFFFF0E4DEFF8C7667FF974744FF944340FF944340FF6D422FFF00000000CE72
          6FFFDDA8A3FFD79F9BFF715A48FF0A0A0AFF36241BFFFFFFFFFFF7F1EEFFF0E4
          DEFFE1CABDFF8C7667FF9E504DFF974744FF944340FF6D422FFF00000000CE72
          6FFFE3B0ABFFDDA8A3FF715A48FF715A48FF715A48FF715A48FF715A48FF715A
          48FF715A48FF715A48FFA45956FF9E504DFF974744FF6D422FFF00000000CE72
          6FFFEDBDB8FFE7B5B0FFE0ACA7FFDAA49FFFD49B97FFCB8E8AFFC58682FFBF7E
          79FFB97571FFB26B68FFAB625FFFA45956FF9E504DFF6D422FFF00000000CE72
          6FFFF0C1BCFFEDBDB8FFE7B5B0FFE0ACA7FFDAA49FFFD49B97FFCE938EFFC88A
          86FFC2827EFFBC7975FFB26B68FFAB625FFFA45956FF6D422FFF00000000CE72
          6FFFF0C1BCFFF0C1BCFFC8635CFFC8635CFFC8635CFFC8635CFFC8635CFFC863
          5CFFC8635CFFC8635CFFC8635CFFB5706CFFAE6763FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFAF5F3FFF6EEEAFFF2E7E2FFEEE2DAFFEBDCD3FFE7D6
          CBFFE4D0C4FFE1CABDFFE1CABDFFC8635CFFB5706CFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFCF8F7FFF8F1EEFFF4EAE6FFF0E4DEFFECDF
          D6FFE9D9CFFFE6D3C8FFE2CDC0FFC8635CFFBC7975FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1EEFFF4EAE6FFF0E4
          DEFFECDFD6FFE9D9CFFFE6D3C8FFC8635CFFC2827EFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1EEFFF4EA
          E6FFF0E4DEFFECDFD6FFE9D9CFFFC8635CFFC88A86FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8F7FFF8F1
          EEFFF4EAE6FFF0E4DEFFECDFD6FFC8635CFFD19792FF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCF8
          F7FFF8F1EEFFF4EAE6FFF0E4DEFFC8635CFF0A0A0AFF6D422FFF00000000CE72
          6FFFF0C1BCFFC8635CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFCF8F7FFF8F1EEFFF4EAE6FFC8635CFFC88A86FF6D422FFF00000000CE72
          6FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE72
          6FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFFCE726FFF}
      end
      item
        Image.Data = {
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
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000414141473636
          363602020202000000000000000010101010AFAFAFB3F3F4F4FFCBCBCBD20505
          050526262626DBDBDBFCCFCFCFFF8787879A2626262600000000C5C8CAFF9599
          9CDF1F1F1F1F000000000000000013131313C7C7C7C9B6B5B5FF929291F15C5B
          5B6717171717ABABABE66C6C6CFF797A7AFFC1C1C1E744444444818487BB7C86
          8CFF818586AD3C3C3C3C27272728525151799FA1A2E7989A9BFF4A4D4EFF838A
          91F45B5B5E624342424A797979E6454545FF6E6E6FFFD6D6D6E9161717177F83
          85BB939C9FFFA4A5A5DE959594D67E7F7FFF515557FF555D60FF5F6B70FF535E
          67FF97989AEE5454545C9D9D9DB96F7172FF20282BFF97989AFF000000003232
          32329B9FA1EB6F777DFF6C747DFF6F7579FF595B5DFF293236FF536269FF898E
          8EFFA3A1A1FFBEBEBEF7EBE8E9F2D6D2D5FF4F565CFF404648FF000000002525
          2525A6A8A8E24A5A69FF3D5472FF52627BFF545E62FF354246FF3C484CFF7075
          79FFA6A7AAFFE8E9E8FFC3C8C5FFC7CEC7FF949E9DFF354146FF000000002626
          262A858D8EE4435561FF3A516EFF31455DFF33444AFF304148FF4F595FFF8D91
          94FF78787BB09797969B419E76E812AE6DFF53A180FF535A65FF000000007677
          778365757CF9344248FF394248FF2F4049FF30454BFF263E53FF586879FFAAAB
          ACFF89898CAB3C35323E00713DAB00E89DFF4AB789FF6F6F79FF000000007374
          758252666EF92C3E45FF2C3539FF19282EFF304147FF36495DFF45576DFF434E
          55FF727784FF979292B81B8E5FC900DB9BFF38A377FF7F7F87FF000000001D1D
          1D2C566064E8263842FF18262EFF081920FF29383EFF3C4247FF434F55FF606D
          73FF5A616BFF7B8081FC34AD7EFD05D79EFF17865DFF97959DED000000001414
          14147E7E7EB63E4F56FF122832FF0A1E26FF192830FF323D42FF4C585CFF6976
          7BFF70767EFF535D60FF24986DFF0DD4A0FF44AE83FF4E474A5B000000001C1C
          1C1C89898AC0374B54FF0E2934FF0C222CFF192B32FF283B43FF44565CFF5B6B
          70FF6E747EFF5E6269FF2F966EFF21DBADFF218458C908080808000000001F1F
          1F1F8C8D8FC55B6B72F8344A53FF172D36FF162B34FF22353EFF2B3E46FF4B59
          61FF56676BFF306652FF1A9C6FFF1ED8B0FF007547CA00261160000000000000
          000022222225404143576D7174A5828E92FF20343CFF152831FF1A2F38FF2D3A
          44FF3B5751F5269E6BF320C9A4FF00BD9CFF29CBA6FF1A8D58E9000000000000
          000000000000000000000E0E0E0E77777887707779DD3E4F56FF0C2029FF3A45
          4BFF7B7C7DCD18422B613FB390EB4FD9C3FF3DAA88E60D291B48000000000000
          0000000000000000000000000000000000001D1D1D1D6A6D6E899EA6A8FDADB0
          B1FF625F6066000000000C3D246732A36FE6082D185100000000}
      end>
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 152
    Top = 176
  end
  object TcpClient1: TTcpClient
    Left = 272
    Top = 176
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 120
    Top = 176
  end
end