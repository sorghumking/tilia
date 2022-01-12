object NewAdminUnit: TNewAdminUnit
  Left = 377
  Top = 485
  BorderStyle = bsDialog
  Caption = 'New Administrative Unit'
  ClientHeight = 415
  ClientWidth = 642
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 329
    Top = 16
    Width = 297
    Height = 329
    BevelInner = bvLowered
    BevelKind = bkFlat
    BevelOuter = bvNone
    BorderStyle = bsNone
    Color = clBtnFace
    Ctl3D = False
    Lines.Strings = (
      '1. Enter the type of administrative unit (e.g. National Park).'
      ''
      '2. Click the radio button for the geopolitical division under '
      'which the administrative unit falls, either administratively or '
      'geographically.'
      ''
      '3. If the geopolitical division is the second or third level, '
      'more than one geopolitical unit may be selected.'
      ''
      'The geopolitical units may be the ones in which the '
      'administrative unit occurs, rather than the one under which '
      'it falls administratively. For example, Yellowstone National '
      'Park (YNP) is administered by the United States federal '
      'government; however, it lies in the states of Wyoming, '
      'Montana, and Idaho. If YNP is listed under the United '
      'States, it will appear in the Administrative Units list box '
      'when the United States is selected as the First Geopolitical '
      'Division. However, if YNP is checked for the states of '
      'Wyoming, Montana, and Idaho, it will appear in the '
      'Administrative Units list box only when one of those three '
      'states is selected.')
    ParentCtl3D = False
    TabOrder = 4
  end
  object Panel1: TPanel
    Left = 16
    Top = 144
    Width = 297
    Height = 201
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object cxCheckComboBox1: TcxCheckComboBox
      Left = 16
      Top = 96
      Properties.ShowEmptyText = False
      Properties.DropDownSizeable = True
      Properties.EditValueFormat = cvfStatesString
      Properties.Items = <>
      Properties.OnChange = cxCheckComboBox1PropertiesChange
      Style.BorderStyle = ebs3D
      TabOrder = 1
      Width = 265
    end
    object cxCheckComboBox2: TcxCheckComboBox
      Left = 16
      Top = 163
      Properties.ShowEmptyText = False
      Properties.DropDownSizeable = True
      Properties.EditValueFormat = cvfStatesString
      Properties.Items = <>
      Properties.OnChange = cxCheckComboBox2PropertiesChange
      Properties.OnClickCheck = cxCheckComboBox2PropertiesClickCheck
      Style.BorderStyle = ebs3D
      TabOrder = 2
      Width = 265
    end
    object Edit1: TEdit
      Left = 16
      Top = 32
      Width = 265
      Height = 19
      Color = clBtnFace
      Ctl3D = False
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 0
    end
    object RadioButton1: TRadioButton
      Left = 16
      Top = 12
      Width = 257
      Height = 17
      Caption = 'Country'
      TabOrder = 3
    end
    object RadioButton2: TRadioButton
      Left = 16
      Top = 76
      Width = 265
      Height = 17
      Caption = 'State'
      TabOrder = 4
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 16
      Top = 140
      Width = 265
      Height = 17
      Caption = 'County'
      TabOrder = 5
      OnClick = RadioButton3Click
    end
  end
  object Panel2: TPanel
    Left = 16
    Top = 16
    Width = 297
    Height = 113
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 56
      Width = 28
      Height = 13
      Caption = 'Type:'
    end
    object LabeledEdit1: TLabeledEdit
      Left = 16
      Top = 24
      Width = 265
      Height = 19
      Color = clBtnFace
      Ctl3D = False
      EditLabel.Width = 31
      EditLabel.Height = 13
      EditLabel.Caption = 'Name:'
      ParentCtl3D = False
      ReadOnly = True
      TabOrder = 1
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 72
      Width = 265
      Height = 21
      Sorted = True
      TabOrder = 0
    end
  end
  object cxButton1: TcxButton
    Left = 232
    Top = 376
    Width = 81
    Height = 25
    Caption = '&Ok'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
    TabOrder = 2
    OnClick = cxButton1Click
  end
  object cxButton2: TcxButton
    Left = 329
    Top = 376
    Width = 81
    Height = 25
    Caption = '&Cancel'
    LookAndFeel.Kind = lfOffice11
    ModalResult = 2
    TabOrder = 3
  end
  object cxButton3: TcxButton
    Left = 114
    Top = 376
    Width = 81
    Height = 25
    Hint = 'Upload new depositional type(s) to Neotoma'
    Caption = '&Upload '
    LookAndFeel.Kind = lfOffice11
    ModalResult = 1
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
    TabOrder = 5
    Visible = False
    OnClick = cxButton3Click
  end
end
