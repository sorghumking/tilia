object SiteHierarchyForm: TSiteHierarchyForm
  Left = 0
  Top = 0
  Caption = 'Site Hierarchy'
  ClientHeight = 347
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageScroller1: TPageScroller
    Left = 0
    Top = 0
    Width = 635
    Height = 347
    Align = alClient
    Control = TreeView1
    Orientation = soVertical
    TabOrder = 0
    object TreeView1: TTreeView
      Left = 0
      Top = 0
      Width = 635
      Height = 347
      Align = alClient
      Indent = 19
      TabOrder = 0
    end
  end
end
