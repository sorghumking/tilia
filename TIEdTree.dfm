object EditTreeForm: TEditTreeForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Edit Tree'
  ClientHeight = 392
  ClientWidth = 256
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnDeactivate = FormDeactivate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 272
    Width = 256
    Height = 80
    Align = alBottom
    Color = 15984090
    ParentBackground = False
    TabOrder = 2
    Visible = False
    object LabeledEdit1: TLabeledEdit
      Left = 8
      Top = 22
      Width = 237
      Height = 21
      EditLabel.Width = 50
      EditLabel.Height = 13
      EditLabel.Caption = 'New Item:'
      TabOrder = 0
      OnChange = LabeledEdit1Change
      OnEnter = LabeledEdit1Enter
      OnExit = LabeledEdit1Exit
    end
    object cxButton1: TcxButton
      Left = 8
      Top = 49
      Width = 75
      Height = 25
      Caption = 'Sibling'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      TabOrder = 1
      OnClick = cxButton1Click
    end
    object cxButton2: TcxButton
      Left = 89
      Top = 49
      Width = 75
      Height = 25
      Caption = 'Child'
      Enabled = False
      LookAndFeel.Kind = lfOffice11
      TabOrder = 2
      OnClick = cxButton2Click
    end
    object cxButton5: TcxButton
      Left = 170
      Top = 49
      Width = 75
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      TabOrder = 3
      OnClick = cxButton5Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 352
    Width = 256
    Height = 40
    Align = alBottom
    Color = 15984090
    ParentBackground = False
    TabOrder = 3
    object cxButton3: TcxButton
      Left = 48
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Ok'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 1
      TabOrder = 0
    end
    object cxButton4: TcxButton
      Left = 137
      Top = 6
      Width = 75
      Height = 25
      Caption = 'Cancel'
      LookAndFeel.Kind = lfOffice11
      ModalResult = 2
      TabOrder = 1
    end
  end
  object dxTreeView1: TdxTreeView
    Left = 0
    Top = 0
    Width = 256
    Height = 247
    ShowNodeHint = True
    OnCustomDraw = dxTreeView1CustomDraw
    DragMode = dmAutomatic
    Indent = 19
    OnEdited = dxTreeView1Edited
    OnChange = dxTreeView1Change
    OnDeletion = dxTreeView1Deletion
    Align = alClient
    ParentColor = False
    SelectedIndex = -1
    TabOrder = 0
  end
  object cxButton6: TcxButton
    Left = 0
    Top = 247
    Width = 256
    Height = 25
    Align = alBottom
    Caption = 'Add New Item'
    LookAndFeel.Kind = lfOffice11
    TabOrder = 1
    OnMouseEnter = cxButton6MouseEnter
    OnMouseLeave = cxButton6MouseLeave
    OnClick = cxButton6Click
  end
end
