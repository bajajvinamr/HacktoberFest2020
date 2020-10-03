//
//  ViewController.swift
//  Translucence
//
//  Created by Swamita on 03/05/20.
//  Copyright © 2020 Swamita. All rights reserved.
//

import UIKit



class ViewController: UIViewController, BlurVCDelegate {
    func removeBlurView() {
        for subview in view.subviews {
            if subview.isKind(of: UIVisualEffectView.self) {
                subview.removeFromSuperview()
            }
        }
    }
    
    
    @IBAction func blurBtnPressed(_ sender: Any) {
        let blurVC = BlurVC()
        blurVC.modalPresentationStyle = .custom
        present(blurVC, animated: true, completion: nil)
        setBlurView()
        
        blurVC.delegate = self
    }
    
    func setBlurView() {]
        let blurView = UIVisualEffectView()
        blurView.frame = view.frame
        blurView.effect = UIBlurEffect(style: .regular)
        view.addSubview(blurView)
    }
}

