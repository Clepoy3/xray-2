﻿#pragma checksum "..\..\property_grid.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "6EC40727B4F65AD6CC619470533DA7CF"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.4016
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.Windows;
using System.Windows.Automation;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Forms.Integration;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Media.TextFormatting;
using System.Windows.Navigation;
using System.Windows.Shapes;
using xray.editor.wpf_controls;
using xray.editor.wpf_controls.converters;
using xray.editor.wpf_controls.property_grid_editors;
using xray.editor.wpf_controls.property_grid_item_editors;


namespace xray.editor.wpf_controls {
    
    
    /// <summary>
    /// property_grid
    /// </summary>
    public partial class property_grid : System.Windows.Controls.ContentControl, System.Windows.Markup.IComponentConnector, System.Windows.Markup.IStyleConnector {
        
        
        #line 9 "..\..\property_grid.xaml"
        internal xray.editor.wpf_controls.property_grid this_ctrl;
        
        #line default
        #line hidden
        
        
        #line 40 "..\..\property_grid.xaml"
        internal System.Windows.Controls.ItemsControl PropertiesPanel;
        
        #line default
        #line hidden
        
        private bool _contentLoaded;
        
        /// <summary>
        /// InitializeComponent
        /// </summary>
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public void InitializeComponent() {
            if (_contentLoaded) {
                return;
            }
            _contentLoaded = true;
            System.Uri resourceLocater = new System.Uri("/wpf_controls;component/property_grid.xaml", System.UriKind.Relative);
            
            #line 1 "..\..\property_grid.xaml"
            System.Windows.Application.LoadComponent(this, resourceLocater);
            
            #line default
            #line hidden
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        void System.Windows.Markup.IComponentConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 1:
            this.this_ctrl = ((xray.editor.wpf_controls.property_grid)(target));
            
            #line 10 "..\..\property_grid.xaml"
            this.this_ctrl.GotFocus += new System.Windows.RoutedEventHandler(this.this_ctrl_GotFocus);
            
            #line default
            #line hidden
            
            #line 11 "..\..\property_grid.xaml"
            this.this_ctrl.LostFocus += new System.Windows.RoutedEventHandler(this.this_ctrl_LostFocus);
            
            #line default
            #line hidden
            return;
            case 2:
            this.PropertiesPanel = ((System.Windows.Controls.ItemsControl)(target));
            return;
            }
            this._contentLoaded = true;
        }
        
        [System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [System.ComponentModel.EditorBrowsableAttribute(System.ComponentModel.EditorBrowsableState.Never)]
        [System.Diagnostics.CodeAnalysis.SuppressMessageAttribute("Microsoft.Design", "CA1033:InterfaceMethodsShouldBeCallableByChildTypes")]
        void System.Windows.Markup.IStyleConnector.Connect(int connectionId, object target) {
            switch (connectionId)
            {
            case 3:
            
            #line 57 "..\..\property_grid.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.expand_collapse_group_Click);
            
            #line default
            #line hidden
            break;
            case 4:
            
            #line 63 "..\..\property_grid.xaml"
            ((System.Windows.Controls.Button)(target)).Click += new System.Windows.RoutedEventHandler(this.expand_collapse_group_Click);
            
            #line default
            #line hidden
            break;
            }
        }
    }
}
