object NewContactForm: TNewContactForm
  Left = 429
  Top = 488
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'New Contact'
  ClientHeight = 426
  ClientWidth = 332
  Color = 10841658
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object FlowPanel1: TFlowPanel
    Left = 0
    Top = 0
    Width = 332
    Height = 377
    Align = alTop
    Color = 15984090
    ParentBackground = False
    TabOrder = 0
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Family name: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 85
      Top = 1
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 0
    end
    object Label2: TLabel
      Left = 1
      Top = 22
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Given names: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit2: TEdit
      Left = 85
      Top = 22
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 1
      OnExit = Edit2Exit
    end
    object Label3: TLabel
      Left = 1
      Top = 43
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Leading initials: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit3: TEdit
      Left = 85
      Top = 43
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 2
    end
    object Label4: TLabel
      Left = 1
      Top = 64
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Suffix: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit4: TEdit
      Left = 85
      Top = 64
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 3
    end
    object Label10: TLabel
      Left = 1
      Top = 85
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Title: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ComboBox2: TComboBox
      Left = 85
      Top = 85
      Width = 234
      Height = 21
      Style = csDropDownList
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 4
      Items.Strings = (
        'Dr.'
        'Dra.'
        'Prof.'
        'Prof. Dr.'
        'Mr.'
        'Mrs.'
        'Miss'
        'Ms.')
    end
    object Label11: TLabel
      Left = 1
      Top = 106
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Status: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object ComboBox3: TComboBox
      Left = 85
      Top = 106
      Width = 234
      Height = 21
      Style = csDropDownList
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 5
      Items.Strings = (
        'active'
        'deceased'
        'defunct'
        'extant'
        'inactive'
        'retired'
        'unknown')
    end
    object Label5: TLabel
      Left = 1
      Top = 127
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Telephone: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit5: TEdit
      Left = 85
      Top = 127
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 6
    end
    object Label6: TLabel
      Left = 1
      Top = 148
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Fax: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit6: TEdit
      Left = 85
      Top = 148
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 7
    end
    object Label7: TLabel
      Left = 1
      Top = 169
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Email: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit7: TEdit
      Left = 85
      Top = 169
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 8
    end
    object Label12: TLabel
      Left = 1
      Top = 190
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'URL: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Edit8: TEdit
      Left = 85
      Top = 190
      Width = 234
      Height = 21
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 9
    end
    object Label8: TLabel
      Left = 1
      Top = 211
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Address: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 85
      Top = 211
      Width = 234
      Height = 76
      Ctl3D = True
      ParentCtl3D = False
      ScrollBars = ssVertical
      TabOrder = 10
      WordWrap = False
    end
    object Label13: TLabel
      Left = 1
      Top = 287
      Width = 84
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Notes: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Memo2: TMemo
      Left = 85
      Top = 287
      Width = 234
      Height = 76
      Ctl3D = True
      ParentCtl3D = False
      ScrollBars = ssVertical
      TabOrder = 11
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 377
    Width = 332
    Height = 49
    Align = alClient
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 1
    object FlowPanel2: TFlowPanel
      Left = 72
      Top = 12
      Width = 194
      Height = 25
      AutoSize = True
      AutoWrap = False
      BevelOuter = bvNone
      TabOrder = 0
      object cxButton1: TcxButton
        Left = 0
        Top = 0
        Width = 65
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.ImageIndex = 0
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton1Click
      end
      object cxButton2: TcxButton
        Left = 65
        Top = 0
        Width = 65
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 1
        OptionsImage.Images = cxImageList1
        TabOrder = 1
      end
      object cxButton3: TcxButton
        Left = 130
        Top = 0
        Width = 64
        Height = 25
        Caption = 'Upload'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 2
        OnClick = cxButton3Click
      end
    end
  end
  object ipwXMLp1: TipwXMLp
    Left = 288
    Top = 440
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 25166104
    ImageInfo = <
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
end
