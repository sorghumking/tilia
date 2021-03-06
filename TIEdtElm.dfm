object EditElementsForm: TEditElementsForm
  Left = 1067
  Top = 149
  BorderStyle = bsDialog
  Caption = 'Edit Elements'
  ClientHeight = 293
  ClientWidth = 845
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel7: TPanel
    Left = 0
    Top = 0
    Width = 845
    Height = 274
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object FlowPanel2: TFlowPanel
      Left = 8
      Top = 8
      Width = 836
      Height = 217
      BevelOuter = bvNone
      TabOrder = 0
      object Label1: TLabel
        Left = 0
        Top = 0
        Width = 128
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Dataset Type'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 128
        Top = 0
        Width = 128
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Taxa Group'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 256
        Top = 0
        Width = 176
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Element'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 432
        Top = 0
        Width = 128
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Symmetry'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 560
        Top = 0
        Width = 140
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Portion'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 700
        Top = 0
        Width = 128
        Height = 15
        Alignment = taCenter
        AutoSize = False
        Caption = 'Maturity'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ListBox1: TListBox
        Left = 0
        Top = 15
        Width = 128
        Height = 135
        ExtendedSelect = False
        ItemHeight = 13
        Sorted = True
        TabOrder = 0
        OnClick = ListBox1Click
      end
      object ListBox3: TListBox
        Left = 128
        Top = 15
        Width = 128
        Height = 135
        ExtendedSelect = False
        ItemHeight = 13
        Sorted = True
        TabOrder = 4
        OnClick = ListBox3Click
      end
      object ListBox2: TListBox
        Left = 256
        Top = 15
        Width = 176
        Height = 135
        ExtendedSelect = False
        ItemHeight = 13
        Sorted = True
        TabOrder = 5
        OnClick = ListBox2Click
      end
      object CheckListBox1: TCheckListBox
        Left = 432
        Top = 15
        Width = 128
        Height = 135
        OnClickCheck = CheckListBox1ClickCheck
        ItemHeight = 13
        Sorted = True
        TabOrder = 1
      end
      object CheckListBox2: TCheckListBox
        Left = 560
        Top = 15
        Width = 140
        Height = 135
        OnClickCheck = CheckListBox2ClickCheck
        ItemHeight = 13
        Sorted = True
        TabOrder = 2
      end
      object CheckListBox3: TCheckListBox
        Left = 700
        Top = 15
        Width = 128
        Height = 135
        OnClickCheck = CheckListBox3ClickCheck
        ItemHeight = 13
        Sorted = True
        TabOrder = 3
      end
      object Label7: TLabel
        Left = 0
        Top = 150
        Width = 128
        Height = 15
        AutoSize = False
        Caption = 'New Dataset Type'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label8: TLabel
        Left = 128
        Top = 150
        Width = 128
        Height = 15
        AutoSize = False
        Caption = 'New Taxa Group'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 256
        Top = 150
        Width = 176
        Height = 15
        AutoSize = False
        Caption = 'New Element'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 432
        Top = 150
        Width = 128
        Height = 15
        AutoSize = False
        Caption = 'New Symmetry'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label11: TLabel
        Left = 560
        Top = 150
        Width = 140
        Height = 15
        AutoSize = False
        Caption = 'New Portion'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Label12: TLabel
        Left = 700
        Top = 150
        Width = 128
        Height = 15
        AutoSize = False
        Caption = 'New Maturity'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 0
        Top = 165
        Width = 128
        Height = 21
        TabOrder = 6
        OnChange = Edit1Change
      end
      object Edit6: TEdit
        Left = 128
        Top = 165
        Width = 128
        Height = 21
        TabOrder = 7
        OnChange = Edit6Change
      end
      object Edit2: TEdit
        Left = 256
        Top = 165
        Width = 176
        Height = 21
        TabOrder = 8
        OnChange = Edit2Change
      end
      object Edit3: TEdit
        Left = 432
        Top = 165
        Width = 128
        Height = 21
        TabOrder = 9
        OnChange = Edit3Change
      end
      object Edit4: TEdit
        Left = 560
        Top = 165
        Width = 140
        Height = 21
        TabOrder = 10
        OnChange = Edit4Change
      end
      object Edit5: TEdit
        Left = 700
        Top = 165
        Width = 128
        Height = 21
        TabOrder = 11
        OnChange = Edit5Change
      end
      object Panel1: TPanel
        Left = 0
        Top = 186
        Width = 128
        Height = 25
        BevelOuter = bvNone
        TabOrder = 12
        object FlowPanel1: TFlowPanel
          Left = 40
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton1: TcxButton
            Left = 0
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Add new Dataset Type'
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
            Hint = 'Delete Dataset Type'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 1
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = cxButton2Click
          end
        end
      end
      object Panel2: TPanel
        Left = 128
        Top = 186
        Width = 128
        Height = 25
        BevelOuter = bvNone
        TabOrder = 13
        object FlowPanel3: TFlowPanel
          Left = 40
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton3: TcxButton
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
            OnClick = cxButton3Click
          end
          object cxButton4: TcxButton
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
            OnClick = cxButton4Click
          end
        end
      end
      object Panel3: TPanel
        Left = 256
        Top = 186
        Width = 176
        Height = 25
        BevelOuter = bvNone
        TabOrder = 14
        object FlowPanel4: TFlowPanel
          Left = 64
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton5: TcxButton
            Left = 0
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Add new element'
            Enabled = False
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 0
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = cxButton5Click
          end
          object cxButton6: TcxButton
            Left = 24
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Delete element'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 1
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = cxButton6Click
          end
        end
      end
      object Panel4: TPanel
        Left = 432
        Top = 186
        Width = 128
        Height = 25
        BevelOuter = bvNone
        TabOrder = 15
        object FlowPanel5: TFlowPanel
          Left = 40
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton7: TcxButton
            Left = 0
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Add new symmetry'
            Enabled = False
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 0
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = cxButton7Click
          end
          object cxButton8: TcxButton
            Left = 24
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Delete symmetry'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 1
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = cxButton8Click
          end
        end
      end
      object Panel5: TPanel
        Left = 560
        Top = 186
        Width = 140
        Height = 25
        BevelOuter = bvNone
        TabOrder = 16
        object FlowPanel6: TFlowPanel
          Left = 40
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton9: TcxButton
            Left = 0
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Add new portion'
            Enabled = False
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 0
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = cxButton9Click
          end
          object cxButton10: TcxButton
            Left = 24
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Delete portion'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 1
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = cxButton10Click
          end
        end
      end
      object Panel6: TPanel
        Left = 700
        Top = 186
        Width = 128
        Height = 25
        BevelOuter = bvNone
        TabOrder = 17
        object FlowPanel7: TFlowPanel
          Left = 40
          Top = 0
          Width = 48
          Height = 25
          AutoSize = True
          AutoWrap = False
          BevelOuter = bvNone
          TabOrder = 0
          object cxButton11: TcxButton
            Left = 0
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Add new maturity'
            Enabled = False
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 0
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 0
            OnClick = cxButton11Click
          end
          object cxButton12: TcxButton
            Left = 24
            Top = 0
            Width = 24
            Height = 25
            Hint = 'Delete maturity'
            LookAndFeel.Kind = lfOffice11
            OptionsImage.ImageIndex = 1
            OptionsImage.Images = cxImageList1
            ParentShowHint = False
            ShowHint = True
            TabOrder = 1
            OnClick = cxButton12Click
          end
        end
      end
    end
    object FlowPanel8: TFlowPanel
      Left = 268
      Top = 239
      Width = 302
      Height = 26
      BevelOuter = bvNone
      TabOrder = 1
      object cxButton13: TcxButton
        Left = 0
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Ok'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 1
        OptionsImage.ImageIndex = 2
        OptionsImage.Images = cxImageList1
        TabOrder = 0
        OnClick = cxButton13Click
      end
      object cxButton14: TcxButton
        Left = 75
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Cancel'
        LookAndFeel.Kind = lfOffice11
        ModalResult = 2
        OptionsImage.ImageIndex = 5
        OptionsImage.Images = cxImageList1
        TabOrder = 1
      end
      object cxButton15: TcxButton
        Left = 150
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Save'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 4
        OptionsImage.Images = cxImageList1
        TabOrder = 2
        OnClick = cxButton15Click
      end
      object cxButton16: TcxButton
        Left = 225
        Top = 0
        Width = 75
        Height = 25
        Caption = 'Upload'
        Enabled = False
        LookAndFeel.Kind = lfOffice11
        OptionsImage.ImageIndex = 6
        OptionsImage.Images = cxImageList1
        TabOrder = 3
        OnClick = cxButton16Click
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 274
    Width = 845
    Height = 19
    Panels = <>
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'xml'
    Filter = 'XML Lookup File (*.xml)|*.xml'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Title = 'Save Elements Lookup File'
    Left = 752
    Top = 232
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 15205064
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
          00000000000000000002000000070000000C0000001000000012000000110000
          000E000000080000000200000000000000000000000000000000000000000000
          000100000004000101120D2A1D79184E36C6216B4BFF216B4BFF216C4BFF1A53
          3AD20F2F21840001011500000005000000010000000000000000000000000000
          0005050F0A351C5B40DC24805CFF29AC7EFF2CC592FF2DC894FF2DC693FF2AAE
          80FF258560FF1A563DD405110C3D00000007000000010000000000000003040E
          0A31206548ED299D74FF2FC896FF2EC996FF56D4ACFF68DAB5FF3BCD9DFF30C9
          96FF32CA99FF2BA479FF227050F805110C3D00000005000000000000000A1A57
          3DD02EA57CFF33CA99FF2EC896FF4CD2A8FF20835CFF00673BFF45BE96FF31CB
          99FF31CB98FF34CC9CFF31AD83FF1B5C41D300010113000000020B23185E2E8A
          66FF3BCD9EFF30CA97FF4BD3A9FF349571FF87AF9DFFB1CFC1FF238A60FF45D3
          A8FF36CF9FFF33CD9BFF3ED0A3FF319470FF0F32237F00000007184D37B63DB3
          8CFF39CD9FFF4BD5A9FF43A382FF699782FFF8F1EEFFF9F3EEFF357F5DFF56C4
          A1FF43D5A8FF3ED3A4FF3CD1A4FF41BC95FF1B5C43CD0000000B1C6446DF4BCA
          A4FF44D2A8FF4FB392FF4E826AFFF0E9E6FFC0C3B5FFEFE3DDFFCEDDD4FF1B75
          4FFF60DCB8FF48D8ACFF47D6AAFF51D4ACFF247A58F80000000E217050F266D9
          B8FF46D3A8FF0B6741FFD2D2CBFF6A8F77FF116B43FF73967EFFF1E8E3FF72A2
          8BFF46A685FF5EDFBAFF4CD9AFFF6BE2C2FF278460FF020604191E684ADC78D9
          BEFF52DAB1FF3DBA92FF096941FF2F9C76FF57DEB8FF2D9973FF73967EFFF0EA
          E7FF4F886CFF5ABB9AFF5BDEB9FF7FE2C7FF27835FF80000000C19523BAB77C8
          B0FF62E0BCFF56DDB7FF59DFBAFF5CE1BDFF5EE2BEFF5FE4C1FF288C67FF698E
          76FFE6E1DCFF176B47FF5FD8B4FF83D5BDFF1E674CC60000000909201747439C
          7BFF95ECD6FF5ADFBAFF5EE2BDFF61E4BFFF64E6C1FF67E6C5FF67E8C7FF39A1
          7EFF1F6D4AFF288B64FF98EFD9FF4DAC8CFF1036286D00000004000000041C5F
          46B578C6ADFF9AEED9FF65E5C0FF64E7C3FF69E7C6FF6BE8C8FF6CE9C9FF6BEA
          C9FF5ED6B6FF97EDD7FF86D3BBFF237759D20102010C0000000100000001030A
          0718247B5BDA70C1A8FFB5F2E3FF98F0DAFF85EDD4FF75EBCEFF88EFD6FF9CF2
          DDFFBAF4E7FF78CDB3FF2A906DEA0615102E0000000200000000000000000000
          0001030A07171E694FB844AB87FF85D2BBFFA8E6D6FFC5F4EBFFABE9D8FF89D8
          C1FF4BB692FF237F60CB05130E27000000030000000000000000000000000000
          000000000001000000030A241B411B60489D258464CF2C9D77EE258867CF1F71
          56B00E3226560000000600000002000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000028160B30000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000007946228F361F0F400000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000001B100820BD6C34DF0D07041000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000AF622FCF6B3B1D8000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000077411F8FCA6D36EF0D070310000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000005B301670DB753EFF4D271160000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000331A0C40DD783EFF8C4620AFD05F29FFD05F
          29FFD05F29FFD05F29FFD05F29FFD05F29FFD05F29FFA2481CCF000000000000
          0000000000000000000000000000401F0D50DE783EFF9A4B22BFD05F29FFDA76
          45FFD8713CFFD9713AFFDD6F36FFDC6932FFA3471CCF0C050210000000000000
          0000000000000000000000000000642F1480E47B41FFA65024CFD05F29FFD672
          40FFD36B35FFD76F39FFDF7947FFB04E21DF0C05021000000000000000000000
          0000000000000000000000000000A34B20CFE57A40FF97441EBFD05F29FFD671
          40FFD77442FFD56D38FFDD7A47FFD16534FF2510073000000000000000000000
          000000000000000000003E1C0C50D56935FFE37941FF883E1CAFD05F29FFDB82
          56FFDF8A62FFDD8053FFD56C37FFDE7B4AFFC46032EF57261070000000000000
          00000000000031160940C0592AEFE37841FFD86C38FF49200E60D05F29FFDD8D
          67FFBC552BEFD7794FFFDC7F50FFD46C36FFDE7A49FFD76E3DFFB35126DF9944
          1FBFA64B22CFD46633FFE0743EFFE0743EFFBB5326EF0C050210D05F29FFA34C
          29CF0C0502107031168FD47247FFDE8357FFD7713EFFD76F3AFFDC7440FFDE72
          3DFFDD713BFFDB703AFFDE723CFFCF602FFF3C190A5000000000A64C21CC0C05
          021000000000000000003E1A0B50B4572FDFDA7A4FFFDD7E50FFDB7645FFDA72
          3FFFDC703CFFD86735FFBC5226EF3C190B5000000000000000000F0703120000
          0000000000000000000000000000000000004B1E0C608A3C1DAF984623BF9744
          21BF95401DBF54230E700C050210000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000040000
          00130000001E0000002000000020000000200000002100000021000000210000
          002200000022000000220000002300000021000000160000000500000012281E
          16CB37291EFF463A31FFBD8150FFBC7E4DFFB97949FFB67646FFB37141FFB06D
          3DFFAD6839FFAB6535FF42362EFF3D3026FF241A13CE00000015000000193B2C
          21FF685C54FF483C34FFE8C28BFFE7C088FFE6BD85FFE5BB81FFE4B87CFFE3B5
          79FFE2B276FFE2B273FF443931FF51433AFF34261DFF0000001E000000183E2F
          24FF6C6057FF4A3F37FFD9B27DFFD8B07BFFD7AE77FFD7AB74FFD6A970FFD5A6
          6DFFD4A56AFFD4A268FF473B33FF5B4F47FF37291EFF0000001D000000164031
          26FF6F645CFF4C4038FFFFFFFFFFF7F1EBFFF7F0EBFFF7F0EBFFF7EFEBFFF6EF
          EAFFF6EFEAFFF6EFE9FF463B34FF5D5249FF3A2C21FF0000001B000000144434
          29FF73675FFF4F443CFFFFFFFFFFF8F2EDFFF8F1EDFFF7F1EDFFF7F0EDFFF8F1
          EBFFF7F0EBFFF7F0ECFF4A4037FF5F534BFF3D2E23FF00000019000000124637
          2CFF776B63FF50453DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFFFF4E433BFF61544CFF403126FF0000001700000010493A
          2FFF796E66FF50453DFF61564EFF60564EFF60554DFF5F544CFF5E544CFF5E53
          4BFF5D524AFF5C5249FF5B5149FF61554DFF433429FF000000150000000E4C3D
          32FF7C706AFF674E44FF654B42FF634A41FF61473FFF5F473EFF5C443CFF5B43
          3AFF594139FF584038FF573F37FF63574FFF46362DFF000000130000000D4E3F
          35FF80746DFF6B5248FFF4ECE6FFE9DACEFFE9D8CDFFE9D8CCFFE9D8CBFFE8D7
          CAFFF3EAE2FFF3E9E2FF5A4139FF645850FF483A2FFF000000110000000B5142
          36FF827770FF70564DFFF9F5F2FFF4EAE4FFF1E6DEFFEBDCD2FFE9D9CCFF4E41
          3DFF60534CFFF3EAE3FF5D453CFF655951FF4C3D32FF0000000F000000095344
          39FF857A73FF755A50FFFAF6F3FFF5EDE7FFF4EDE6FFF4ECE6FFEFE2DAFF493D
          38FF5A4D46FFF4EBE4FF60483FFF655A52FF4F3F34FF0000000D000000075545
          3AFF887D76FF795E54FFFAF6F4FFF5EEE9FFF5EDE7FFF4EDE7FFF4ECE6FF473A
          36FF483D36FFE9D9CDFF644C43FF675A52FF514137FF0000000B000000065748
          3DFF898079FF7C6157FFFAF7F4FFFAF6F4FFFAF6F4FFFAF6F3FFFAF6F3FFFAF5
          F2FFF5EEE9FFF4ECE6FF695046FF82776FFF534439FF00000009000000034235
          2EC058493DFF7F645AFF998178FF967F75FF937A72FF8E786DFF8B7269FF866E
          64FF82695FFF7D645BFF6E544AFF56453BFF3F332BC200000005000000000000
          0002000000030000000400000004000000040000000400000005000000050000
          0005000000050000000500000006000000060000000400000001}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000020000000C05031A46110852AB190C76E31D0E89FF1C0E89FF190C
          76E4120852AD06031B4D0000000E000000030000000000000000000000000000
          000301010519130A55A9211593FF2225AEFF2430C2FF2535CBFF2535CCFF2430
          C3FF2225AFFF211594FF140B58B20101051E0000000400000000000000020101
          03151C1270CD2522A6FF2D3DCCFF394BD3FF3445D1FF2939CDFF2839CDFF3344
          D0FF394AD4FF2D3CCDFF2523A8FF1C1270D20101051D00000003000000091912
          5BA72A27AAFF2F41D0FF3541C7FF2726ABFF3137BCFF384AD3FF384BD3FF3137
          BCFF2726ABFF3540C7FF2E40D0FF2927ACFF1A115EB10000000D08061C3D3129
          A2FD2C3CCCFF3842C6FF5F5DBDFFEDEDF8FF8B89CEFF3337B9FF3437B9FF8B89
          CEFFEDEDF8FF5F5DBDFF3741C6FF2B3ACDFF3028A4FF0907204A1E185F9F373B
          BCFF3042D0FF2621A5FFECE7ECFFF5EBE4FFF8F2EEFF9491D1FF9491D1FFF8F1
          EDFFF3E9E2FFECE6EBFF2621A5FF2E3FCFFF343ABEFF201A66B0312A92E03542
          CBFF3446D1FF2C2FB5FF8070ADFFEBDBD3FFF4EAE4FFF7F2EDFFF8F1EDFFF4E9
          E2FFEADAD1FF7F6FACFF2B2EB5FF3144D0FF3040CBFF312A95E53E37AEFA3648
          D0FF374AD3FF3A4ED5FF3234B4FF8A7FB9FFF6ECE7FFF5ECE6FFF4EBE5FFF6EB
          E5FF897DB8FF3233B4FF384BD3FF3547D2FF3446D1FF3E37AEFA453FB4FA4557
          D7FF3B50D5FF4C5FDAFF4343B7FF9189C7FFF7EFE9FFF6EEE9FFF6EFE8FFF7ED
          E8FF9087C5FF4242B7FF495DD8FF394CD4FF3F52D4FF443FB3FA403DA1DC5967
          DAFF5B6EDDFF4F4DBAFF8F89CAFFFBF6F4FFF7F1ECFFEDE1D9FFEDE0D9FFF7F0
          EAFFFAF5F2FF8F89CAFF4E4DB9FF576ADCFF5765D9FF403EA4E12E2D70987C85
          DDFF8798E8FF291D9BFFE5DADEFFF6EEEBFFEDDFDAFF816EA9FF816EA9FFEDDF
          D8FFF4ECE7FFE5D9DCFF291D9BFF8494E7FF7A81DDFF33317BAC111125356768
          D0FC9EACEDFF686FCEFF5646A1FFCCB6BCFF7A68A8FF4C4AB6FF4D4BB7FF7A68
          A8FFCBB5BCFF5646A1FF666DCCFF9BAAEEFF696CD0FD1212273F000000043B3B
          79977D84DFFFA5B6F1FF6D74D0FF2D219BFF5151B9FF8EA2ECFF8EA1ECFF5252
          BBFF2D219BFF6B72D0FFA2B3F0FF8086E0FF404183A700000008000000010303
          050C4E509DBC8087E2FFAEBDF3FFA3B6F1FF9DAFF0FF95A9EEFF95A8EEFF9BAD
          EFFFA2B3F0FFACBCF3FF838AE3FF4F52A0C10303051100000002000000000000
          000100000005323464797378D9F8929CEAFFA1AEEFFFB0BFF3FFB0BFF4FFA2AE
          EFFF939DE9FF7479DAF83234647D000000080000000200000000000000000000
          000000000000000000031213232D40437D935D61B5D07378DFFC7378DFFC5D61
          B5D040437D951212223000000004000000010000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00E9E9E900EBEBEB00FFFF
          FF00FFFFFF00F7F7F700D5D5D500E4E4E400FFFFFF00FFFFFF00C2C3C400BBBE
          C000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00D1D1D100B1B1B100F7F6
          F600FFFFFF00E2E2E2009696960090909000D1D1D100FFFFFF00C8CACC00727D
          8300DFE0E100FFFFFF00FFFFFF00FDFDFD00DADADA00C7C8C800696A6A008B8F
          9300F2F3F400FAFAFA00AAAAAA006A6A6A007E7D7D00D8D8D800FFFFFF00CDD1
          D2008A949700C8CBCC00E6E5E500AAAAAA00696C6D00828789007B8588006571
          7B009BA0A600F9F9F900EFEFEF00858585005257580083858700FFFFFF00FFFF
          FF00C8CBCD00888F92008A8F940085898C00818485003F44460067757A008B93
          960093949300CACACA00EEEEEE00D7D8D800646D710059626500FFFFFF00FFFF
          FF00E3E4E40075828900627487006E7E91007F888E0055606400546268008287
          8900ACAEB000CFCECE00D8D8D800EFEEEE00CCCECF005E696D00FFFFFF00FFFF
          FF00D7DADA0064737B005B718C004C64830050616B0051626800536166007B82
          85008E929900ECECEC00F3F3F300F9F9F900F9F9F90077828700FFFFFF00FEFE
          FE00A1AAAE0053646B00515B6500485866004D606800465C6800576C7D00B4B7
          B700DCDCDC00F8F8F900FFFFFF00FFFFFF00FFFFFF00A7AFB200FFFFFF00FFFE
          FE008A969B00475E6600545D610033444C00445960004B5F6D00586F8A006873
          790060697300D0D3D700FFFFFF00FFFFFF00FFFFFF00A9B1B400FFFFFF00FFFF
          FF00949B9F003A5059003B4D5400182E3700384C5400535D6200535F6B00727F
          85006F7A82008D949900DDDDDE00FEFEFE00EFF0F0008E9A9E00FFFFFF00FFFF
          FF00D5D5D50057666B002F48510018343F00253D460048565C00555F63007A87
          8C0087919500717B8000989D9F00F8F8F800A4ACAF00B9C0C300FFFFFF00FFFF
          FF00F2F1F0006C797E00324F5A00203F4A00233D47003C505900596B72007482
          8800818C9200818C91008B9498009EA3A6009CA5A800FBFCFC00FFFFFF00FFFF
          FF00DDDDDC005D6B7000324D58002B46510029454F00394F5800435860006071
          780075848A00768489007F888B00B3B8BA00F7F8F800FFFFFF00FFFFFF00FFFF
          FF00FBFBFB00D8DBDC00B8BFC2007C898F00364D5600344B5400395159004258
          610062717700848D9100DADBDB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00F4F4F4008D979A0043565E0028414B003145
          4E0079808300EBEBEB00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FDFDFC00CACECF00859297007880
          8400D3D3D300FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00}
        MaskColor = clWhite
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000230000
          0033000000330000003300000033000000330000002300000000000000000000
          0023000000330000003300000033000000330000003300000023555452C07674
          72FF706D6CFF6D6A69FF696765FF666362FF444241C000000000000000005554
          52C0767472FF706D6CFF6D6A69FF696765FF666362FF444241C07A7876FF817E
          7DFF9C9996FF898583FF716F6CFF595756FF605D5CFF00000000000000007A78
          76FF817E7DFF9C9996FF898583FF716F6CFF595756FF615E5DFF777573FFCFCF
          CFFFD9D7D6FFD0CFCEFFC8C8C7FFC3C1C1FF5E5A59FF00000000000000007775
          73FFD0CFCFFFD9D7D6FFD0CFCEFFC8C8C7FFC3C1C1FF5E5B5AFF767472FFB3B1
          AFFFCAC9C7FFB0AEADFF91908EFF757472FF5E5A59FF00000033000000337775
          73FFB3B1AFFFCAC9C7FFB0AEADFF91908EFF757572FF5F5C5BFF767472FFB3B1
          AFFFCAC9C7FFB1AEAEFF939290FF777674FF5E5A59FF7A7876FF646260FF7775
          73FFB3B1AFFFCAC9C7FFB1AEAEFF939290FF777674FF605D5CFF767472FFB3B0
          AEFFCAC9C7FFB0ADADFF91908EFF757472FF5B5857FF767472FF615F5DFF7674
          72FFB3B1AFFFCAC9C7FFB0ADADFF91908EFF757573FF5F5C5BFF777472FFDEDD
          DDFFEBEBE9FFDBDAD9FFCAC9C8FFBBBAB9FF575453FFD6D5D3FF8C8B89FF7573
          71FFDEDDDCFFEBEBE9FFDBDAD9FFCAC9C8FFBCBCBBFF5E5B5AFF7A7876FF6F6D
          6BFF666261FF605D5CFF5E5C5AFF5E5A5AFF2C2B2B9BD3D2D0FF8A8987FF3C3B
          3A9B6C6A68FF646160FF625F5EFF615F5DFF615E5DFF403E3DA8000000007774
          73FFBCBAB8FFCDCBCAFFA5A3A2FF7E7C7BFF595655FFD6D5D3FF8C8C89FF7673
          72FFBCBAB7FFCCCAC9FFA4A2A1FF7E7C7BFF5F5C5BFF00000000000000007774
          73FFB9B7B5FFC9C7C6FFA2A09FFF7D7B7AFF5C5858FF777472FF615F5DFF7774
          73FFB9B8B5FFC9C7C6FFA2A09FFF7E7C7BFF605D5CFF00000000000000007875
          74FFBDBBB9FFCECCCBFFA5A3A2FF7E7C7BFF5E5B5AFF7B7977FF646260FF7976
          75FFBCBBB8FFCECCCBFFA6A4A3FF807E7DFF605D5CFF00000000000000005352
          50AE716E6DFF696665FF64605FFF625E5DFF383736AA00000000000000004746
          45AA6F6C6BFF696665FF676463FF656261FF444241AE00000000000000000000
          000000000033787574FFCBCAC7FF9B9A99FF625E5DFF00000000000000007875
          74FFCAC8C6FF989796FF605D5CFF000000330000000000000000000000000000
          00007A7976FF908D8CFF908E8CFF656461FF615E5DFF00000000000000007977
          75FF8E8B8AFF918F8DFF686664FF63605FFF0000000000000000000000000000
          00007B7977FF73716FFF6D6B69FF696665FF625F5EFF00000000000000007B79
          77FF73716FFF6D6B69FF696665FF63605FFF0000000000000000}
      end>
  end
  object TcpClient1: TTcpClient
    Left = 48
    Top = 232
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 88
    Top = 232
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 128
    Top = 232
  end
end
