object NeotomaContactForm: TNeotomaContactForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Neotoma Contact'
  ClientHeight = 578
  ClientWidth = 695
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 695
    Height = 105
    Align = alTop
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 0
    object cxGroupBox1: TcxGroupBox
      Left = 219
      Top = 8
      Caption = 'Search (use % for wild card)'
      ParentFont = False
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebsFlat
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.LookAndFeel.Kind = lfFlat
      Style.TextColor = clNavy
      Style.TextStyle = []
      Style.TransparentBorder = True
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 0
      Height = 89
      Width = 238
      object FlowPanel3: TFlowPanel
        Left = 8
        Top = 24
        Width = 226
        Height = 44
        BevelOuter = bvNone
        Color = 15984090
        ParentBackground = False
        TabOrder = 0
        object cxLabel1: TcxLabel
          Left = 0
          Top = 0
          AutoSize = False
          Caption = 'Family Name:'
          Height = 17
          Width = 129
        end
        object cxLabel2: TcxLabel
          Left = 129
          Top = 0
          AutoSize = False
          Caption = 'Initials:'
          Height = 17
          Width = 50
        end
        object cxTextEdit1: TcxTextEdit
          Left = 0
          Top = 17
          ParentFont = False
          Properties.AutoSelect = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -11
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.LookAndFeel.Kind = lfFlat
          Style.IsFontAssigned = True
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 2
          Width = 129
        end
        object cxTextEdit2: TcxTextEdit
          Left = 129
          Top = 17
          ParentFont = False
          Properties.AutoSelect = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clWindowText
          Style.Font.Height = -11
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.LookAndFeel.Kind = lfFlat
          Style.IsFontAssigned = True
          StyleDisabled.LookAndFeel.Kind = lfFlat
          StyleFocused.LookAndFeel.Kind = lfFlat
          StyleHot.LookAndFeel.Kind = lfFlat
          TabOrder = 3
          Width = 50
        end
        object cxButton2: TcxButton
          Left = 179
          Top = 17
          Width = 44
          Height = 21
          LookAndFeel.Kind = lfOffice11
          OptionsImage.ImageIndex = 0
          OptionsImage.Images = cxImageList1
          TabOrder = 4
          OnClick = cxButton2Click
        end
      end
    end
    object cxGroupBox2: TcxGroupBox
      Left = 1
      Top = 8
      Caption = 'Instuctions:'
      ParentFont = False
      Style.BorderColor = clNavy
      Style.BorderStyle = ebsSingle
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.TextColor = clNavy
      Style.IsFontAssigned = True
      TabOrder = 2
      Height = 89
      Width = 208
      object cxRichEdit1: TcxRichEdit
        Left = 2
        Top = 18
        Align = alClient
        ParentFont = False
        Properties.ReadOnly = True
        Properties.ScrollBars = ssVertical
        Style.BorderStyle = ebsNone
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clMaroon
        Style.Font.Height = -11
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = []
        Style.Shadow = False
        Style.TextColor = clMaroon
        Style.IsFontAssigned = True
        StyleFocused.BorderStyle = ebsNone
        StyleHot.BorderStyle = ebsNone
        TabOrder = 0
        Height = 69
        Width = 204
      end
    end
    object cxGroupBox3: TcxGroupBox
      Left = 468
      Top = 8
      Caption = 'Contacts Found (* = Alias):'
      ParentFont = False
      Style.BorderColor = clNavy
      Style.BorderStyle = ebsFlat
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clNavy
      Style.Font.Height = -11
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.LookAndFeel.Kind = lfFlat
      Style.TextColor = clNavy
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 1
      Height = 89
      Width = 224
      object cxListBox1: TcxListBox
        Left = 2
        Top = 18
        Width = 220
        Height = 69
        Align = alClient
        AutoComplete = False
        ExtendedSelect = False
        ItemHeight = 13
        Sorted = True
        Style.BorderStyle = cbsNone
        Style.Shadow = False
        TabOrder = 0
        OnClick = cxListBox1Click
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 511
    Width = 695
    Height = 48
    Align = alBottom
    BevelOuter = bvNone
    Color = 15984090
    ParentBackground = False
    TabOrder = 1
    object cxButton3: TcxButton
      Left = 263
      Top = 12
      Width = 115
      Height = 25
      Caption = 'Update Contact'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 3
      OptionsImage.Images = cxImageList1
      TabOrder = 0
      Visible = False
      OnClick = cxButton3Click
    end
    object cxButton1: TcxButton
      Left = 193
      Top = 12
      Width = 64
      Height = 25
      Caption = 'Match'
      LookAndFeel.Kind = lfOffice11
      OptionsImage.ImageIndex = 2
      OptionsImage.Images = cxImageList1
      TabOrder = 1
      OnClick = cxButton1Click
    end
    object cxButton4: TcxButton
      Left = 454
      Top = 12
      Width = 64
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      OptionsImage.ImageIndex = 5
      OptionsImage.Images = cxImageList1
      TabOrder = 2
    end
    object cxButton5: TcxButton
      Left = 384
      Top = 12
      Width = 64
      Height = 25
      Caption = 'Finish'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      OptionsImage.ImageIndex = 4
      OptionsImage.Images = cxImageList1
      TabOrder = 3
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 105
    Width = 695
    Height = 406
    Align = alClient
    BevelOuter = bvLowered
    Color = 15984090
    ParentBackground = False
    TabOrder = 2
    object Panel6: TPanel
      Left = 325
      Top = 1
      Width = 45
      Height = 404
      Align = alClient
      Color = 15984090
      ParentBackground = False
      TabOrder = 2
      object cxButtonRightArrow: TcxButton
        Left = 6
        Top = 30
        Width = 32
        Height = 32
        Hint = 'New Neotoma contact'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFC15700FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFC76B18FFC15700FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFE08800FFC96510FFC15700FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFF4C239FFE08800FFC9630FFFC15700FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000BC5300FFE59000FFF1B929FFE08800FFC96310FFC15700FF0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C45C04FFE28E00FFE28B00FFEEAF1DFFE08800FFC96310FFC157
          00FF000000000000000000000000000000000000000000000000C76110FFC45B
          0CFFC2580BFFC0580BFFC1550BFFBE550AFFBD530AFFBC5409FFBC530AFFBA52
          08FFBA5109FFC35B08FFEB9700FFE28B00FFE08800FFF1B01AFFE08800FFC160
          16FFC7620FFF0000000000000000000000000000000000000000CE6E13FFEFB1
          3CFFF5BC42FFF2B53AFFF0B135FFF0AB2FFFEEA82AFFECA126FFEB9E22FFEA99
          1BFFE89616FFE79511FFEB990BFFE99506FFE58E00FFE08800FFEEA60DFFE187
          00FFC16016FFC6600EFF00000000000000000000000000000000C97014F4F7CC
          57FFFAD562FFF9CE58FFF8CC4FFFF7C648FFF6C342FFF5C03CFFF4B833FFF2B1
          2DFFF2AF24FFEFA81FFFEDA117FFEB9E10FFEA9709FFE89302FFE18800FFEBA1
          07FFE18700FFC16016FFC55F0EFF000000000000000000000000CD7515F4F7D0
          5BFFFCD86AFFF9CD5EFFF8CB57FFF6CA51FFF6C64AFFF6C445FFF4BE3DFFF3BA
          38FFF2B531FFF1AD2AFFEFA823FFEDA51CFFEDA115FFEC9C0FFFEA9708FFE187
          00FFEC9F02FFE18700FFC05F15FFC55E0CFF0000000000000000D17A19F4F9D5
          64FFFDDC75FFFAD668FFF9D261FFF8CE5EFFF7CC56FFF6C84FFFF6C449FFF5C1
          42FFF4BD3DFFF3B734FFF1B02EFFF0AD27FFEFA922FFEDA41AFFEC9F13FFEB9B
          0CFFEA9000FFEA9600FFF0B83BFFD07621FFC45D0CFF00000000D4801CF4FBD9
          6DFFFEE07DFFFBDB72FFFBD76BFFFAD365FFF9D160FFF8CD59FFF6CA52FFF7CB
          4DFFF6C447FFF4BF41FFF4BA3AFFF3B533FFF1B12DFFF0AC26FFEEA71EFFEEA3
          18FFEB9E10FFE28A00FFF4BE2AFFF6D67FFFE19A3BFFC5600EFFD8851DF4FCDE
          76FFFEE586FFFDE079FFFBDD77FFFBDA70FFFBD76BFFFAD366FFF8D05EFFF8CB
          57FFF7CA51FFF7C64EFFF5C345FFF4BE3FFFF3BA39FFF3B432FFF1AF2DFFEFAC
          22FFED9F11FFF4C43DFFF6D67FFFE19A3BFFD37E25FFC55F0EFFDA8E1EF4FDE2
          77FFFFE88CFFFEE381FFFDE27BFFFDDE77FFFBDC71FFFBDA6CFFFAD666FFF9D0
          60FFF8CC59FFF7CA54FFF6CB4FFFF6C549FFF5C141FFF4BD3EFFF3B632FFF0AA
          23FFF4C43DFFF6D67FFFE19B37FFD37E25FFC45E0CFF00000000DD9222F4FCE3
          80FFFFEA95FFFEE68BFFFDE585FFFEE27EFFFDE07EFFFDDF76FFFADC72FFFBDA
          6CFFFBD669FFF9D261FFF8CF59FFF7CB57FFF6CA50FFF6C245FFF4BB35FFF4C4
          3DFFF6D67FFFF0AA23FFD37E25FFC55F0EFF0000000000000000E2A130F4FFF5
          CFFFFFF8DBFFFFF6D4FFFFF6D5FFFFF5D3FFFFF4D2FFFFF3CEFFFFF2CBFFFFF1
          C7FFFFF1C9FFFDEBB2FFFAD461FFF9D161FFF8CB55FFF7C94DFFF6D67FFFF6D6
          7FFFF0AA23FFD37E25FFC55F0EFF000000000000000000000000EC9E20FFFAE6
          A4FFFBEAACFFFBE8A8FFFBE7A8FFFAE8A6FFF9E7A6FFF9E6A4FFF9E5A3FFF9E4
          A1FFF8E3A0FFF9DF93FFFBDB6FFFFAD462FFF8D05BFFF6D67FFFFAEBB9FFF4BB
          35FFD37E25FFC55F0EFF00000000000000000000000000000000EDA429FFEA9A
          1CFFE8961AFFE8961AFFE7941AFFE79319FFE69018FFE68F19FFE59118FFE48C
          18FFE28B14FFE49427FFFDE274FFFCDD76FFFEF1C0FFFCEEBEFFF4BB35FFD37E
          25FFC5600EFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFFFEE88AFFFFF6D3FFF8E8B1FFF5CD67FFD37E25FFC560
          0EFF000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F2B439FFFFFCE4FFFAEBB3FFF5CD67FFD37E25FFC55F0EFF0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFFFDECABFFF5CD67FFD37E25FFC55F0EFF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F3B632FFF5CD67FFD37E25FFCD6E1CFF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFFD37E25FFCA6918FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000D37E25FFCA6918FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OptionsImage.ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = cxButtonRightArrowClick
      end
      object cxButtonUpdate: TcxButton
        Left = 6
        Top = 65
        Width = 32
        Height = 32
        Hint = 'Update Neotoma contact'
        LookAndFeel.Kind = lfOffice11
        OptionsImage.Glyph.Data = {
          36090000424D3609000000000000360000002800000018000000180000000100
          2000000000000009000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFC15700FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFC76B18FFC15700FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFE08800FFC96510FFC15700FF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C15700FFF9E5A3FFE08800FFC9630FFFC15700FF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000BC5300FFF9E5A3FFF9E5A3FFE08800FFC96310FFC15700FF0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000C45C04FFF9E5A3FF00000000F9E5A3FFE08800FFC96310FFC157
          00FF000000000000000000000000000000000000000000000000C76110FFC45B
          0CFFC2580BFFC0580BFFC1550BFFBE550AFFBD530AFFBC5409FFBC530AFFBA52
          08FFBA5109FFC35B08FFF9E5A3FF0000000000000000F9E5A3FFE08800FFC160
          16FFC7620FFF0000000000000000000000000000000000000000CE6E13FFEFB1
          3CFFF5BC42FFF2B53AFFF0B135FFF0AB2FFFEEA82AFFECA126FFEB9E22FFEA99
          1BFFE89616FFE79511FFF9E5A3FF000000000000000000000000F9E5A3FFE187
          00FFC16016FFC6600EFF00000000000000000000000000000000D47B1FFFF7CC
          57FFF9E5A3FFF9E5A3FFF9E5A3FFF9E5A3FFF9E5A3FFF9E5A3FFF9E5A3FFF9E5
          A3FFF9E5A3FFF9E5A3FFF9E5A3FF00000000000000000000000000000000F9E5
          A3FFE18700FFC16016FFC55F0EFF000000000000000000000000D88020FFF7D0
          5BFFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000F9E5A3FFE18700FFC05F15FFC55E0CFF0000000000000000DC8524FFF9D5
          64FFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F9E5A3FFF0B83BFFD07621FFC45D0CFF00000000DF8B27FFFBD9
          6DFFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000F9E5A3FFF6D67FFFE19A3BFFC5600EFFE39028FFFCDE
          76FFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000F9E5A3FFE19A3BFFD37E25FFC55F0EFFE59929FFFDE2
          77FFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000E19B37FFD37E25FFC45E0CFF00000000E89D2DFFFCE3
          80FFF9E5A3FF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F0AA23FFD37E25FFC55F0EFF0000000000000000EDAC3BFFF9E5
          A3FFF9E5A3FFFFF6D4FFFFF6D5FFFFF5D3FFFFF4D2FFFFF3CEFFFFF2CBFFFFF1
          C7FFFFF1C9FFFDEBB2FF00000000000000000000000000000000000000000000
          0000F0AA23FFD37E25FFC55F0EFF000000000000000000000000EC9E20FFFAE6
          A4FFFBEAACFFFBE8A8FFFBE7A8FFFAE8A6FFF9E7A6FFF9E6A4FFF9E5A3FFF9E4
          A1FFF8E3A0FFF9DF93FF00000000000000000000000000000000FAEBB9FFF4BB
          35FFD37E25FFC55F0EFF00000000000000000000000000000000EDA429FFEA9A
          1CFFE8961AFFE8961AFFE7941AFFE79319FFE69018FFE68F19FFE59118FFE48C
          18FFE28B14FFE49427FF00000000000000000000000000000000F4BB35FFD37E
          25FFC5600EFF0000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFF00000000FFF6D3FF00000000F5CD67FFD37E25FFC560
          0EFF000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F2B439FFFFFCE4FFFFFFFFFFF5CD67FFD37E25FFC55F0EFF0000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFFFFFFFFFFF5CD67FFD37E25FFC55F0EFF000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000F3B632FFF5CD67FFD37E25FFCD6E1CFF00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000EEAB2CFFD37E25FFCA6918FF0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000D37E25FFCA6918FF000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
        OptionsImage.ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = cxButtonUpdateClick
      end
    end
    object FlowPanel1: TFlowPanel
      Left = 1
      Top = 1
      Width = 324
      Height = 404
      Align = alLeft
      Color = 15984090
      ParentBackground = False
      TabOrder = 0
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 318
        Height = 30
        BevelOuter = bvNone
        Caption = 'Tilia Contact'
        Color = 15984090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        object cxTextEditID1: TcxTextEdit
          Left = 261
          Top = 4
          ParentFont = False
          Properties.Alignment.Horz = taRightJustify
          Properties.ReadOnly = True
          Style.BorderColor = clNavy
          Style.BorderStyle = ebsSingle
          Style.Color = 15984090
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.IsFontAssigned = True
          TabOrder = 0
          Visible = False
          Width = 57
        end
        object cxLabelID1: TcxLabel
          Left = 242
          Top = 6
          Caption = 'ID:'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.IsFontAssigned = True
          Visible = False
        end
        object cxSpinEdit1: TcxSpinEdit
          Left = 186
          Top = 4
          ParentFont = False
          Properties.AutoSelect = False
          Properties.CanEdit = False
          Properties.LargeIncrement = 1.000000000000000000
          Properties.MaxValue = 1.000000000000000000
          Properties.MinValue = 1.000000000000000000
          Properties.UseCtrlIncrement = True
          Properties.OnChange = cxSpinEdit1PropertiesChange
          Style.BorderColor = clNavy
          Style.BorderStyle = ebsSingle
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.LookAndFeel.Kind = lfOffice11
          Style.Shadow = False
          Style.TextStyle = []
          Style.ButtonTransparency = ebtNone
          Style.IsFontAssigned = True
          StyleDisabled.LookAndFeel.Kind = lfOffice11
          StyleFocused.BorderStyle = ebsSingle
          StyleFocused.LookAndFeel.Kind = lfOffice11
          StyleHot.BorderStyle = ebsSingle
          StyleHot.LookAndFeel.Kind = lfOffice11
          TabOrder = 2
          Value = 1
          Visible = False
          Width = 42
        end
        object cxButton7: TcxButton
          Left = 4
          Top = 4
          Width = 40
          Height = 22
          Hint = 'Set an alias for this name'
          LookAndFeel.Kind = lfOffice11
          OptionsImage.ImageIndex = 1
          OptionsImage.Images = cxImageList1
          ParentShowHint = False
          ShowHint = True
          TabOrder = 3
          Visible = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          OnClick = cxButton7Click
        end
      end
      object LabelFamilyName1: TLabel
        Left = 1
        Top = 31
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
      object cxTextEditFamilyName1: TcxTextEdit
        Left = 85
        Top = 31
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 1
        Width = 234
      end
      object LabelGivenNames1: TLabel
        Left = 1
        Top = 52
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
      object cxTextEditGivenNames1: TcxTextEdit
        Left = 85
        Top = 52
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 2
        Width = 234
      end
      object LabelInitials1: TLabel
        Left = 1
        Top = 73
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
      object cxTextEditInitials1: TcxTextEdit
        Left = 85
        Top = 73
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 3
        Width = 234
      end
      object LabelSuffix1: TLabel
        Left = 1
        Top = 94
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
      object cxTextEditSuffix1: TcxTextEdit
        Left = 85
        Top = 94
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 4
        Width = 234
      end
      object LabelTitle1: TLabel
        Left = 1
        Top = 115
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
      object cxComboBoxTitle1: TcxComboBox
        Left = 85
        Top = 115
        Properties.Items.Strings = (
          'Dr.'
          'Dra.'
          'Prof.'
          'Prof. Dr.'
          'Mr.'
          'Mrs.'
          'Miss'
          'Ms.')
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 5
        Width = 234
      end
      object LabelStatus1: TLabel
        Left = 1
        Top = 136
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
      object cxComboBoxStatus1: TcxComboBox
        Left = 85
        Top = 136
        Properties.Items.Strings = (
          'active'
          'deceased'
          'defunct'
          'extant'
          'inactive'
          'retired'
          'unknown')
        Properties.ReadOnly = True
        Properties.OnValidate = cxComboBoxStatusPropertiesValidate
        Style.BorderStyle = ebsFlat
        TabOrder = 6
        Width = 234
      end
      object LabelPhone1: TLabel
        Left = 1
        Top = 157
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
      object cxTextEditPhone1: TcxTextEdit
        Left = 85
        Top = 157
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 7
        Width = 234
      end
      object LabelFax1: TLabel
        Left = 1
        Top = 178
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
      object cxTextEditFax1: TcxTextEdit
        Left = 85
        Top = 178
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 8
        Width = 234
      end
      object LabelEmail1: TLabel
        Left = 1
        Top = 199
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
      object cxTextEditEmail1: TcxTextEdit
        Left = 85
        Top = 199
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 9
        Width = 234
      end
      object LabelURL1: TLabel
        Left = 1
        Top = 220
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
      object cxTextEditURL1: TcxTextEdit
        Left = 85
        Top = 220
        Properties.ReadOnly = True
        Style.BorderStyle = ebsFlat
        TabOrder = 10
        Width = 234
      end
      object LabelAddress1: TLabel
        Left = 1
        Top = 241
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
      object cxMemoAddress1: TcxMemo
        Left = 85
        Top = 241
        Properties.ReadOnly = True
        Properties.ScrollBars = ssVertical
        Properties.WordWrap = False
        Style.LookAndFeel.Kind = lfFlat
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 11
        Height = 76
        Width = 234
      end
      object LabelNotes1: TLabel
        Left = 1
        Top = 317
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
      object cxMemoNotes1: TcxMemo
        Left = 85
        Top = 317
        Properties.ReadOnly = True
        Properties.ScrollBars = ssVertical
        Style.LookAndFeel.Kind = lfFlat
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 12
        Height = 76
        Width = 234
      end
    end
    object FlowPanel2: TFlowPanel
      Left = 370
      Top = 1
      Width = 324
      Height = 404
      Align = alRight
      Color = 15984090
      ParentBackground = False
      TabOrder = 1
      object Panel5: TPanel
        Left = 1
        Top = 1
        Width = 318
        Height = 30
        BevelOuter = bvNone
        Caption = 'Neotoma Contact'
        Color = 15984090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 0
        object cxTextEditID2: TcxTextEdit
          Left = 262
          Top = 4
          ParentFont = False
          Properties.Alignment.Horz = taRightJustify
          Properties.ReadOnly = True
          Style.BorderColor = clNavy
          Style.BorderStyle = ebsSingle
          Style.Color = 15984090
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.IsFontAssigned = True
          TabOrder = 0
          Width = 57
        end
        object cxLabel3: TcxLabel
          Left = 242
          Top = 6
          Caption = 'ID:'
          ParentFont = False
          Style.Font.Charset = DEFAULT_CHARSET
          Style.Font.Color = clNavy
          Style.Font.Height = -12
          Style.Font.Name = 'Tahoma'
          Style.Font.Style = []
          Style.IsFontAssigned = True
        end
        object cxButton6: TcxButton
          Left = 4
          Top = 4
          Width = 40
          Height = 22
          Hint = 'More information about contact'
          Caption = '?'
          DropDownMenu = PopupMenu1
          Kind = cxbkDropDown
          LookAndFeel.Kind = lfOffice11
          OptionsImage.Glyph.Data = {
            36030000424D3603000000000000360000002800000010000000100000000100
            18000000000000030000C30E0000C30E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE9E9E9EBEBEBFFFFFFFFFFFFF7F7F7D5D5
            D5E4E4E4FFFFFFFFFFFFC2C3C4BBBEC0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD1
            D1D1B1B1B1F7F6F6FFFFFFE2E2E2969696909090D1D1D1FFFFFFC8CACC727D83
            DFE0E1FFFFFFFFFFFFFDFDFDDADADAC7C8C8696A6A8B8F93F2F3F4FAFAFAAAAA
            AA6A6A6A7E7D7DD8D8D8FFFFFFCDD1D28A9497C8CBCCE6E5E5AAAAAA696C6D82
            87897B858865717B9BA0A6F9F9F9EFEFEF858585525758838587FFFFFFFFFFFF
            C8CBCD888F928A8F9485898C8184853F444667757A8B9396939493CACACAEEEE
            EED7D8D8646D71596265FFFFFFFFFFFFE3E4E47582896274876E7E917F888E55
            6064546268828789ACAEB0CFCECED8D8D8EFEEEECCCECF5E696DFFFFFFFFFFFF
            D7DADA64737B5B718C4C648350616B5162685361667B82858E9299ECECECF3F3
            F3F9F9F9F9F9F9778287FFFFFFFEFEFEA1AAAE53646B515B654858664D606846
            5C68576C7DB4B7B7DCDCDCF8F8F9FFFFFFFFFFFFFFFFFFA7AFB2FFFFFFFFFEFE
            8A969B475E66545D6133444C4459604B5F6D586F8A687379606973D0D3D7FFFF
            FFFFFFFFFFFFFFA9B1B4FFFFFFFFFFFF949B9F3A50593B4D54182E37384C5453
            5D62535F6B727F856F7A828D9499DDDDDEFEFEFEEFF0F08E9A9EFFFFFFFFFFFF
            D5D5D557666B2F485118343F253D4648565C555F637A878C879195717B80989D
            9FF8F8F8A4ACAFB9C0C3FFFFFFFFFFFFF2F1F06C797E324F5A203F4A233D473C
            5059596B72748288818C92818C918B94989EA3A69CA5A8FBFCFCFFFFFFFFFFFF
            DDDDDC5D6B70324D582B465129454F394F5843586060717875848A7684897F88
            8BB3B8BAF7F8F8FFFFFFFFFFFFFFFFFFFBFBFBD8DBDCB8BFC27C898F364D5634
            4B54395159425861627177848D91DADBDBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFF4F4F48D979A43565E28414B31454E798083EBEBEBFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFDFCCA
            CECF859297788084D3D3D3FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
          ParentShowHint = False
          ShowHint = True
          TabOrder = 2
          Visible = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -12
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object Label9: TLabel
        Left = 1
        Top = 31
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
      object cxTextEditFamilyName2: TcxTextEdit
        Left = 85
        Top = 31
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 1
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label14: TLabel
        Left = 1
        Top = 52
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
      object cxTextEditGivenNames2: TcxTextEdit
        Left = 85
        Top = 52
        Properties.OnChange = cxTextEditPropertiesChange
        Properties.OnValidate = cxTextEditGivenNames2PropertiesValidate
        Style.BorderStyle = ebsFlat
        TabOrder = 2
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label15: TLabel
        Left = 1
        Top = 73
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
      object cxTextEditInitials2: TcxTextEdit
        Left = 85
        Top = 73
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 3
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label16: TLabel
        Left = 1
        Top = 94
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
      object cxTextEditSuffix2: TcxTextEdit
        Left = 85
        Top = 94
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 4
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label17: TLabel
        Left = 1
        Top = 115
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
      object cxComboBoxTitle2: TcxComboBox
        Left = 85
        Top = 115
        Properties.Items.Strings = (
          'Dr.'
          'Dra.'
          'Prof.'
          'Prof. Dr.'
          'Mr.'
          'Mrs.'
          'Miss'
          'Ms.')
        Properties.OnChange = cxComboBoxPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 5
        OnEnter = cxComboBoxEnter
        OnExit = cxExit
        Width = 234
      end
      object Label18: TLabel
        Left = 1
        Top = 136
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
      object cxComboBoxStatus2: TcxComboBox
        Left = 85
        Top = 136
        Properties.Items.Strings = (
          'active'
          'deceased'
          'defunct'
          'extant'
          'inactive'
          'retired'
          'unknown')
        Properties.OnChange = cxComboBoxPropertiesChange
        Properties.OnValidate = cxComboBoxStatusPropertiesValidate
        Style.BorderStyle = ebsFlat
        TabOrder = 6
        OnEnter = cxComboBoxEnter
        OnExit = cxExit
        Width = 234
      end
      object Label19: TLabel
        Left = 1
        Top = 157
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
      object cxTextEditPhone2: TcxTextEdit
        Left = 85
        Top = 157
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 7
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label20: TLabel
        Left = 1
        Top = 178
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
      object cxTextEditFax2: TcxTextEdit
        Left = 85
        Top = 178
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 8
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label21: TLabel
        Left = 1
        Top = 199
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
      object cxTextEditEmail2: TcxTextEdit
        Left = 85
        Top = 199
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 9
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label22: TLabel
        Left = 1
        Top = 220
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
      object cxTextEditURL2: TcxTextEdit
        Left = 85
        Top = 220
        Properties.OnChange = cxTextEditPropertiesChange
        Style.BorderStyle = ebsFlat
        TabOrder = 10
        OnEnter = cxTextEditEnter
        OnExit = cxExit
        Width = 234
      end
      object Label23: TLabel
        Left = 1
        Top = 241
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
      object cxMemoAddress2: TcxMemo
        Left = 85
        Top = 241
        Properties.ScrollBars = ssVertical
        Properties.WordWrap = False
        Properties.OnChange = cxMemoPropertiesChange
        Style.LookAndFeel.Kind = lfFlat
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 11
        OnEnter = cxMemoEnter
        OnExit = cxExit
        Height = 76
        Width = 234
      end
      object Label24: TLabel
        Left = 1
        Top = 317
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
      object cxMemoNotes2: TcxMemo
        Left = 85
        Top = 317
        Properties.ScrollBars = ssVertical
        Properties.OnChange = cxMemoPropertiesChange
        Style.LookAndFeel.Kind = lfFlat
        StyleDisabled.LookAndFeel.Kind = lfFlat
        StyleFocused.LookAndFeel.Kind = lfFlat
        StyleHot.LookAndFeel.Kind = lfFlat
        TabOrder = 12
        OnEnter = cxMemoEnter
        OnExit = cxExit
        Height = 76
        Width = 234
      end
    end
    object cxGroupBox4: TcxGroupBox
      Left = 168
      Top = 159
      PanelStyle.Active = True
      PanelStyle.OfficeBackgroundKind = pobkGradient
      Style.BorderStyle = ebsOffice11
      Style.Edges = [bLeft, bTop, bRight, bBottom]
      Style.LookAndFeel.Kind = lfFlat
      Style.Shadow = True
      Style.TransparentBorder = True
      StyleDisabled.LookAndFeel.Kind = lfFlat
      StyleFocused.LookAndFeel.Kind = lfFlat
      StyleHot.LookAndFeel.Kind = lfFlat
      TabOrder = 3
      Visible = False
      Height = 93
      Width = 377
      object cxLabel4: TcxLabel
        Left = 0
        Top = 28
        AutoSize = False
        Caption = 'Contacting Neotoma. Please Wait.'
        ParentFont = False
        Style.Font.Charset = DEFAULT_CHARSET
        Style.Font.Color = clWindowText
        Style.Font.Height = -16
        Style.Font.Name = 'Tahoma'
        Style.Font.Style = [fsBold]
        Style.LookAndFeel.Kind = lfStandard
        Style.Shadow = False
        Style.TextColor = clNavy
        Style.TextStyle = [fsBold]
        Style.IsFontAssigned = True
        StyleDisabled.LookAndFeel.Kind = lfStandard
        StyleFocused.LookAndFeel.Kind = lfStandard
        StyleHot.LookAndFeel.Kind = lfStandard
        Properties.Alignment.Horz = taCenter
        Height = 23
        Width = 375
        AnchorX = 188
      end
      object cxProgressBar1: TcxProgressBar
        Left = 2
        Top = 70
        Align = alBottom
        Properties.AnimationSpeed = 5
        Properties.BarStyle = cxbsBitmap
        Properties.ForegroundImage.Data = {
          920D0000424D920D00000000000036000000280000003C000000130000000100
          1800000000005C0D000000000000000000000000000000000000F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2EDEEEEFAF9F9FBFAFBF8F7F7F8F7F8F6F6F8F7F6F7F6F5
          F7F6F6F8F8F7F9F8F8F9F4F4F4F2F2F2F1F1F1F9F9F9FDFDFDF7F7F7F2F2F2F2
          F2F2FAFAFAFDFDFDFCFCFCFBFAF9F7F6F6F9F9F9F2F2F2FEFFFFF2F2F2FEFEFE
          F2F2F2F2F2F2FAFAFBF2F1F2F3F3F3F4F4F4F4F4F4F3F3F3F0F0F0EFEEEEF6F6
          F7F6F5F5F5F5F5F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2C5C7C8
          8287867B80809097998D9592A0A6A0A9B1A9A9ADA3A2A494ABADA2B6B8B0E0E2
          E0FBFAFBF3F3F3F1F1F1F3F3F3F3F3F3F3F3F3F5F5F5F1F1F1F5F4F4E1E3E3CA
          D1D8D3D8DBE1E0E1EDEDEEF1F1F1EBEBEBDADADABFC0C2D0D2DAD5DDE2E8E7E7
          EAEAEAE6E6E6DADADACACBCBBEBDBD989B9A73787474797FE4E6E5F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F6F6F6FCFCFCFDFDFDFBFBFBFBFBFB
          FAF9FAF4F4F6F1F1F2E5E7E7C6CAC8ABB0A8A5A79AA4A9A5F2F2F2F7F7F7F1F1
          F1F3F3F3F2F2F2F2F2F2F5F5F5E5E6E5D3D7DCB5B5B6B3B6B6BFBFBFCBCBCBD6
          D6D6C8C8C8A9A9A7C4CBC3A8A9A9A4A2A1A09D9C9C9998929190807F80828180
          C2C6BADEE1C9808A877E857EB9BBBBF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F1F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F4F3F4
          F7F6F6FBFBFCE4E5E6A4A5A0A8AEAACACBCBFBFBFBF4F4F4F2F2F2F3F2F2F8F7
          F8888B899B9B97726F6C6C6C6A78787889898A8A8A8B79797963676597A9A997
          ABAF6C80866B828D6B838A4B595F95938AAFC5C092ADB18EA5A5889A966A776F
          B8BABBF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F4F4F4FFFFFF
          B3B6B6919B96CFD2D3F8F8F8F2F2F2FFFFFFB2B3B258615DA9B2AFBCC0B6B0AE
          A384867B565550515051888781BCCACBCCE5EEB3D5E5A2C6D7B1D1DC93B3BFBD
          D9E3BFD4D4A6C3C9B6CAC976827E050405586461F6F5F7F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2FFFEFFB0B3B48E9891EFEFF1
          F8F7F79D9D984E595696ADB6CDDEE0BED5DFD0E7EEDEEFF3C8CAC05D6056C9D4
          D3D0E7F2B5D1E1B2D1E0B5D0DFBBD7E0C0DBEAB8D4E2A4C2D1B8C9C6A1B4AC77
          817A0F0F0B6B7879F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2FEFDFD9AA29DADB2B5DFE5D9E4E5E39FBAC5C7D7D9
          C2D4D8BFD2D8DAE7EDD5E7EFBCDCEDCCE1E9B1D2E4A5C5D5A6C4CBB0CDDAAFCD
          DDA9C9D8A0BDC98FADBEA1B9C2BDC9C7B3C1B99DACA56D807E8D9696FDFCFCF2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F9
          F8F9BDC3BD727A74CBDBDCA6BCC7BBCFDCA9B9C29DB8C2BACDD3D0E1E5CEE3EF
          BCDBEAB8D8F0AED0E6A8C8D9A4BFD099B4BF97B7C796B6C28BA8B5798A8A747F
          83E1E4FB7179867F9494203030FFFFFFF3F3F3F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F8F7F8BCBFBE5D67629FB2B5A8
          BDC9A0B7C687A1AFA5B9C0C5D5DAD2DDE4CBE0EBB9D9EFAACDE2A9CDE4AACCDE
          9ABDD49BB6C590ADB86F889379949B68797C80847FECEBFF76828B495658AEB3
          B5FCFBFBF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F1F1F1F2F2
          F2F2F2F2F2F2F2F2F2F2FFFEFF9097947481818695998B9CA1B7C8CBBACACCC1
          D1D7A6C0CBB2CBD7ADC7D49ABDCF92B2C9A1BFD099B9CC93AFBD72868B65777D
          738D967A8B8E979797E3E4EC7D858A5B6463FFFFFFF2F2F1F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F1F2F1F2F2
          F2FFFFFFA9AEAC72766AABB4AEA4B0AEB3BEBC9FB5BA98AEB9A1B5BCA3BAC39C
          B4C393AFBF819CAEA2C0D5778F9C7F92947281815A6E74535F5FBDBAAD969897
          6C7175929898FCFCFCF2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F1F2F2F2FFFEFFC6C6C39A9C
          8799A198A7AEA991A1A1B5BFBC9FAAA9AAB8B7A7B2AF92A6AD6F849070899867
          7A80647171737F80606D6B909693E2E2E2646A6CB2B6AFCECFCFF6F6F6F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F1FCFBFDCBCBC9868A7A929D9BAAB2ABB3BA
          B3A5B0ABAFB6AFAEB7AF9EA8A47D8A8E56666E59696F4E5B5C596261E2E3E2FF
          FFFFF9F8F9DDDEDDE3E4E6F8F8F8F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2FAFAFBE2E1E0676A64919990A9AEA4B7BAAEAEB3A9A7AEA7969C
          96808D8E5E6B6F485253555E5CF3F3F3F8F7F7F2F2F2F2F2F2F5F4F4F4F4F3F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F1F2F1F1F2F1F1F2F2F2F2F2F2F2F1F1F2F1F1F2F1F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F6F6F7
          F8F7F894969382877F939A919CA49C848E87828C8A87908D707B78AEB2B1FEFD
          FEF5F5F5F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F1F1F2
          F1F1F2F2F2F2F2F2F2F2F1F2F1F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F3F3F3FDFCFDEFEFF1CED2D1
          C4C7C7C0C3C4BDC0C1C9CCCDF3F3F4FCFBFBF3F2F2F1F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2
          F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2F2}
        Properties.Marquee = True
        Properties.ShowText = False
        Style.BorderStyle = ebsNone
        Style.LookAndFeel.Kind = lfOffice11
        Style.TransparentBorder = True
        StyleDisabled.LookAndFeel.Kind = lfOffice11
        StyleFocused.LookAndFeel.Kind = lfOffice11
        StyleHot.LookAndFeel.Kind = lfOffice11
        TabOrder = 1
        Width = 373
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 559
    Width = 695
    Height = 19
    Color = 15984090
    Panels = <>
  end
  object TcpClient1: TTcpClient
    Left = 56
    Top = 520
  end
  object ipsHTTPS1: TipsHTTPS
    SSLCertStore = 'MY'
    TransferredDataLimit = 65536
    Left = 136
    Top = 520
  end
  object PopupMenu1: TPopupMenu
    Left = 432
    Top = 104
    object Publications1: TMenuItem
      Caption = 'Publications'
      OnClick = Publications1Click
    end
    object Datasets1: TMenuItem
      Caption = 'Datasets'
      OnClick = Datasets1Click
    end
  end
  object cxImageList1: TcxImageList
    FormatVersion = 1
    DesignInfo = 34079328
    ImageInfo = <
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000AB7E62FFA477
          5AFF955F3FFF8E5739FF7E4020FF7E4020FF000000000000000000000000AB7E
          62FFA4775AFF955F3FFF8E5739FF7E4020FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FFFCFA
          FAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFFE3C8B8FFCDA38CFFB9805FFF7E4020FF00000000AB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF6F4324FFAB7E62FF9F6B
          4EFF9F6B4EFF915331FF915331FF7E4020FF7E4020FF00000000DDC5A9FFAB7E
          62FFECD8CDFFECD8CDFFCAA089FFAC7655FF7E4020FF9F6B4EFFAB7E62FFECD8
          CDFFECD8CDFFCAA089FFAC7655FF7E4020FF906060FF0000000000000000AB7E
          62FFFFFFFFFFF1E8E5FFEED2C1FFAC7655FF7E4020FFC89890FFAB7E62FFFFFF
          FFFFF1E8E5FFEED2C1FFAC7655FF906060FF0000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF7E4020FF9F6B4EFFAB7E62FF9F6B
          4EFF955F3FFF7E4020FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FFFCFAFAFFDEC3B1FFAC7655FF7E4020FF00000000AB7E62FFFCFA
          FAFFDEC3B1FFAC7655FF7E4020FF000000000000000000000000000000000000
          0000AB7E62FF9F6B4EFF955F3FFF7E4020FF9F6B4EFF00000000AB7E62FF9F6B
          4EFF955F3FFF7E4020FF9F6B4EFF000000000000000000000000000000000000
          000000000000AB7E62FFFCFAFAFF7E4020FF000000000000000000000000AB7E
          62FFFCFAFAFF7E4020FF00000000000000000000000000000000000000000000
          000000000000AB7E62FFAB7E62FF9F6B4EFF000000000000000000000000AB7E
          62FFAB7E62FF9F6B4EFF00000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000}
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FFFFFFFFD8CF
          CCFFD3C6BEFFD2C5BDFFD2C5BDFFD2C5BDFFD2C5BDFFD3C5BFFFC7D1D1FFC3DD
          E3FFD9E5EFFFECEBFBFFEDECFCFFFFFFFFFFFFFFFFFFFFFFFFFFCFB07BFFB17B
          1CFFB07714FFB27916FFB37A17FFB37A17FFB27916FFAA7A1AFF62B479FF46CF
          9CFF56D0A2FF98DFC5FFEDF8F5FFFFFFFFFFFFFFFFFFFFFFFFFFBB8827FFB477
          01FFB67903FFB67A08FFB77D0CFFB77C0EFFB77B09FFAB7C09FF67BC7EFF5FD9
          ABFF45D19BFF2FC98EFF72D4B0FFEFFAF7FFFFFFFFFFFFFFFFFFC89828FFC790
          07FFC9910CFFCB9819FFCC991BFFCB991BFFCB981AFFC8930DFFC89003FFCB98
          24FF50CD9FFF50CD9FFF25C88AFF4FCC9EFFEDEDFBFFFFFFFFFFC89828FFC790
          07FFC9910CFFCB9819FFCC991BFFCB991BFFCB981AFFC8930DFFC89003FFCB98
          24FFC0DDC4FF50CD9FFF25C88AFF4FCC9EFFC9EBE0FFF5FBFAFFCDA447FFD1A3
          33FFD2A93CFFD4AA45FFD4AA45FFD6AA45FFD4AA45FFD3A93FFFD0A232FFC1A0
          3FFF69BF95FF35C993FF2DC98CFF29C88AFF3FC894FF3FC894FFCBB592FFCDAF
          7EFFCEB381FFCDB17BFFCDB17BFFCDB17BFFCDB17BFFCFB37DFFD1B481FF9881
          5BFF4A7F76FF3EC09DFF29BC90FF2CBC92FF3EA68DFF6B7D84FFF5F0E7FFE5D2
          AFFFE5D2ACFFEBD8B2FFE7D7B2FFE9D8B1FFE8D8B3FFE6D5AEFFDBC9A4FF7A71
          63FF525D5AFF50B58FFF33CD92FF41CA96FF50B58FFF676565FFFFFFFFFFFBF9
          F8FFEDE2D4FFCCAD76FFBF9248FFBF9143FFD6B97CFFE6D9BFFFF1EEEAFF8080
          80FF5D6663FF548170FF54D1A3FF54D1A3FF5D6663FF757373FFFFFFFFFFEAE9
          F3FFCCAD76FFBA7F01FFBA8002FFBA8002FFB88102FFD6B97CFFF1EEEAFF8080
          80FF5D6663FF666A75FF54D1A3FF54D1A3FF5D6663FF757373FFFFFFFFFFE8D4
          B1FFBB810AFFBA7F01FFBA8002FFBA8002FFB88102FFB87C00FFE8D4B1FFE5E5
          E5FFA9A9A9FF888686FF7D7B7AFF878486FFAEACABFFE3E3E3FFFFFFFFFFDCBB
          76FFC38901FFC38C03FFC38C03FFC38C03FFC38C01FFC38A00FFDCBB76FFFCF9
          F5FFB8B8B8FF565453FF4C4A4AFF555353FFB6B6B6FFFFFFFFFFFFFFFFFFDCBB
          76FFC38901FFC38C03FFC38C03FFC38C03FFC38C01FFC38A00FFDCBB76FFDAD9
          E3FF676565FF676565FF686666FF686665FF777574FFDBDBE9FFFFFFFFFFEBDD
          C0FFD3AE54FFD5B054FFD5B054FFD7B054FFD5B054FFD4B058FFE8D4B1FFE8E8
          E8FF767473FF676565FF686666FF686665FF777574FFE3E3E3FFFFFFFFFFFFFF
          FFFFE1CDA4FFD5B054FFD5B054FFD5B054FFD5B054FFDFC89AFFF6F1E8FFFAFA
          FAFFA09E9EFF787675FF7A7878FF7B7978FFA4A2A1FFFFFFFFFFFFFFFFFFFFFF
          FFFFE9E7F3FFE0C78FFFE0C78FFFE0C78FFFE0C78FFFE5E0E9FFECECFAFFEDED
          FBFFD9D9E7FFA4A2A1FF7A7878FFA4A2A1FFD8D8E4FFFFFFFFFF}
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
      end
      item
        Image.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000290000000E00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000A10000000A00000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000100000009B0000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000065000000460000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000AB000000030000000000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000038000000F8000000700000000400000000000000000000
          0000000000000000000A00000000000000000000000000000000000000000000
          000000000000000000C1000000FF000000F6000000CC000000900000008B0000
          00C0000000D9000000A1000000B3000000CC0000006000000000000000000000
          000000000000000000EF000000FF000000FF0000008A00000018000000230000
          00F4000000E20000000000000060000000FF000000C700000000000000000000
          000000000056000000BB00000077000000F80000002B000000000000003E0000
          00FF000000A90000000200000074000000FF000000C700000000000000000000
          0000000000CA0000003A00000000000000460000007B000000570000005B0000
          005800000092000000FE0000007D00000070000000BB00000000000000000000
          0004000000E4000000000000000000000098000000FF000000FF000000380000
          0000000000CB000000FF0000006400000000000000A000000000000000000000
          0078000000F60000009A00000019000000F1000000FF000000EF000000030000
          00140000009D000000730000005800000003000000A000000000000000000000
          00E1000000FF000000FF0000009B000000500000007B00000089000000BB0000
          00B90000000000000000000000C4000000DA000000B300000000000000090000
          00E7000000FA000000FF0000003A000000000000000000000096000000FF0000
          0081000000160000002A000000D9000000FF000000C700000000000000090000
          00260000008F000000D50000004D0000002200000005000000E1000000E80000
          00B80000009500000081000000C9000000F1000000CA00000000000000000000
          0000000000000000000D0000005C00000085000000A2000000840000002F0000
          0001000000000000000000000000000000320000007000000000}
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
      end>
  end
  object ipsJSONS1: TipsJSONS
    SSLCertStore = 'MY'
    OnSSLServerAuthentication = ipsJSONS1SSLServerAuthentication
    Left = 16
    Top = 520
  end
end
