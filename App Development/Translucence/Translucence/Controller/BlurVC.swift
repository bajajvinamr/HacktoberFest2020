//
//  BlurVC.swift
//  Translucence
//
//  Created by Swamita on 03/05/20.
//  Copyright © 2020 Swamita. All rights reserved.
//

import UIKit

protocol BlurVCDelegate: class {
    func removeBlurView()
}

class BlurVC: UIViewController {
  
    @IBOutlet weak var tapView: UIView!
  
    weak var delegate: BlurVCDelegate?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let tapToDismiss = UITapGestureRecognizer(target: self, action: #selector(tapToDismiss(_:)))
        tapView.addGestureRecognizer(tapToDismiss)
    }
    
    @objc func tapToDismiss(_ recognizer: UITapGestureRecognizer) {        delegate?.removeBlurView()
        dismiss(animated: true, completion: nil)
    }
}
