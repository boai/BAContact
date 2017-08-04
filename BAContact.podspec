Pod::Spec.new do |s|
    s.name         = 'BAContact'
    s.version      = '1.0.0'
    s.summary      = '通讯录，最简单的中英文混合排序封装，微信通讯录 demo！'
    s.homepage     = 'https://github.com/BAHome/BAContact'
    s.license      = 'MIT'
    s.authors      = { 'boai' => 'sunboyan@outlook.com' }
    s.platform     = :ios, '8.0'
    s.source       = { :git => 'https://github.com/BAHome/BAContact.git', :tag => s.version.to_s }
    s.source_files = 'BAContact/BAContact/*.{h,m}'
    s.requires_arc = true
end
